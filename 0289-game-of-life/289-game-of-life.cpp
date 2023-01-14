// https://leetcode.com/problems/game-of-life/discuss/73230/C++-O(1)-space-O(mn)-time
// https://leetcode.com/problems/game-of-life/discuss/73217/Infinite-board-solution

class Solution {
    int getNeighbours(vector<vector<int>>& board, int i, int j) {
        auto count{0};
        if (i > 0 && j > 0 
            && board[i-1][j-1] % 2 == 1) ++count;
        if (i > 0 
            && board[i-1][j] % 2 == 1) ++count;
        if (i > 0 && j+1 < board[0].size() 
            && board[i-1][j+1] % 2 == 1) ++count;
        if (j > 0 
            && board[i][j-1] % 2 == 1) ++count;
        if (j+1 < board[0].size() 
            && board[i][j+1] % 2 == 1) ++count;
        if (i+1 < board.size() && j > 0
            && board[i+1][j-1] % 2 == 1) ++count;
        if (i+1 < board.size() 
            && board[i+1][j] % 2 == 1) ++count;
        if (i+1 < board.size() && j+1 < board[0].size()
            && board[i+1][j+1] % 2 == 1) ++count;
        return count;
    }
public:
    // to do updates in place, += 2 and >> 1 to get next state
    void gameOfLife(vector<vector<int>>& board) {
        auto m{board.size()};
        auto n{board[0].size()};
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                auto count{getNeighbours(board, i, j)};
                if (count == 3 && board[i][j] == 0) board[i][j] += 2;
                else if ((count == 2 || count == 3) && board[i][j] == 1) board[i][j] += 2;
            }
        }
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                board[i][j] /= 2;
            }
        }
    }
};