class Solution {
private:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index) {
        if (board[i][j] != word[index]) return false;
        if (index+1 == word.size()) return true;
        auto cur{board[i][j]};
        board[i][j] = '*';
        if (i+1 < board.size()) {
            if (dfs(board, i+1, j, word, index+1)) return true;
        }
        if (j+1 < board[0].size()) {
            if (dfs(board, i, j+1, word, index+1)) return true;
        }
        if (i-1 >= 0) {
            if (dfs(board, i-1, j, word, index+1)) return true;
        }
        if (j-1 >= 0) {
            if (dfs(board, i, j-1, word, index+1)) return true;
        }
        board[i][j] = cur;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (auto i = 0; i < board.size(); ++i) {
            for (auto j = 0; j < board[0].size(); ++j) {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};

// [["a"]]
// "a"