class Solution {
public:
    // bfs to find the answer
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> s;
        queue<string> q;
        queue<string> next;
        string cur = "";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                cur += '0' + board[i][j];
            }
        }
        q.push(cur);
        int ans = 0;
        int index;
        while (!q.empty()) {
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                if (cur == "123450") return ans;
                if (s.find(cur) != s.end()) continue;
                s.insert(cur);
                for (int i = 0; i < 6; ++i) {
                    if (cur[i] == '0') {
                        index = i;
                        break;
                    }
                }

                // vertical move
                if (index < 3) {
                    swap(cur[index], cur[index + 3]);
                    next.push(cur);
                    swap(cur[index], cur[index + 3]);
                }
                else {
                    swap(cur[index], cur[index - 3]);
                    next.push(cur);
                    swap(cur[index], cur[index - 3]);
                }

                // horizontal move
                if (index < 3) {
                    if (index + 1 < 3) {
                        swap(cur[index], cur[index + 1]);
                        next.push(cur);
                        swap(cur[index], cur[index + 1]);
                    }
                    if (index - 1 >= 0) {
                        swap(cur[index], cur[index - 1]);
                        next.push(cur);
                        swap(cur[index], cur[index - 1]);
                    }
                }
                else {
                    if (index + 1 < 6) {
                        swap(cur[index], cur[index + 1]);
                        next.push(cur);
                        swap(cur[index], cur[index + 1]);
                    }
                    if (index - 1 >= 3) {
                        swap(cur[index], cur[index - 1]);
                        next.push(cur);
                        swap(cur[index], cur[index - 1]);
                    }
                }
            }
            ++ans;
            swap(q, next);
        }
        return -1;
    }
};