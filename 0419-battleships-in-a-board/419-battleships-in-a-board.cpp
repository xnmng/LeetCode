class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        auto ans{0};
        for (auto i = 0; i < board.size(); ++i) {
            for (auto j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'X') {
                    if (j > 0 && board[i][j-1] == 'X') {
                        continue;
                    }
                    if (i > 0 && board[i-1][j] == 'X') {
                        continue;
                    }
                    ++ans;
                }
            }
        }
        return ans;
    }
};

// [["X","X","X"]]