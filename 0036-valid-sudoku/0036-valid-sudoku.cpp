class Solution {
private:
    bool isValid(vector<vector<char>>& board, int a, int b) {
        unordered_set<char> s;
        for (auto i = 0; i < 3; ++i) {
            for (auto j = 0; j < 3; ++j) {
                if (board[i+a][j+b] != '.' 
                    && !s.insert(board[i+a][j+b]).second) return false;
            }
        }
        return true;
    }    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto i = 0; i < 9; ++i) {
            unordered_set<char> s1;
            unordered_set<char> s2;
            for (auto j = 0; j < 9; ++j) {
                if (board[i][j] != '.' && !s1.insert(board[i][j]).second) {
                    // cout << "error " << i << " " << j << "\n";
                    return false;
                }
                if (board[j][i] != '.' && !s2.insert(board[j][i]).second) {
                    // cout << "error " << j << " " << i << "\n";
                    return false;
                }
            }
        }
        // cout << "ok\n";
        auto a{0};
        auto b{0};
        while (a != 9) {
            if (!isValid(board, a, b)) return false;
            b += 3;
            if (b == 9) {
                a += 3;
                b = 0;
            }
        }
        return true;
    }
};