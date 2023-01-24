// if youre currently on a square with snake/ladder, you must still roll the dice!
// https://youtu.be/6lH4nO3JfLk
class Solution {
private:
    // given x (current board square), returns the respective coordinate in board
    // or last square if >= last square steps
    pair<int,int> get(int x, int n) {
        --x;
        if (x / n >= n) return {n-1, n-1};
        return {x / n, x % n};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        reverse(board.begin(), board.end());
        for (auto i = 1; i < board.size(); i += 2) {
            reverse(board[i].begin(), board[i].end());
        }
        auto n{board.size()};
        vector<int> dp(n * n + 1, 0);
        auto t{0};
        pair<int,int> z;
        queue<int> q;
        queue<int> next;
        q.push(1);                              // start on first square
        int cur;
        while (!q.empty()) {
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                if (dp[cur] == 1) continue;     // already visited
                dp[cur] = 1;                    // mark as visited
                if (cur == n * n) return t;
                for (auto i = 1; i <= 6; ++i) {
                    z = get(cur + i, n);
                    if (board[z.first][z.second] != -1) {
                        next.push(board[z.first][z.second]);
                    }
                    else {
                        next.push(cur + i);
                    }
                }
            }
            swap(q, next);
            ++t;
        }
        return -1;
    }
};

// [[1,1,-1],[1,1,1],[-1,1,1]]
// [[-1,-1,2,21,-1],[16,-1,24,-1,4],[2,3,-1,-1,-1],[-1,11,23,18,-1],[-1,-1,-1,23,-1]]
// [[-1,-1,-1,-1,48,5,-1],[12,29,13,9,-1,2,32],[-1,-1,21,7,-1,12,49],[42,37,21,40,-1,22,12],[42,-1,2,-1,-1,-1,6],[39,-1,35,-1,-1,39,-1],[-1,36,-1,-1,-1,-1,5]]