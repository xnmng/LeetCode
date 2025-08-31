class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        constexpr int n = 9;
        vector<pair<int, int>> empty_cells;
        vector<vector<int>> rows, columns, squares;
        rows = columns = squares = vector<vector<int>>(n, vector<int>(n + 1));
        
        const auto get_square_idx = [](int r, int c) {
            return (r / 3) * 3 + c / 3;
        };
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == '.') {
                    empty_cells.emplace_back(r, c);
                }
                else {
                    const int v = board[r][c] - '0';
                    rows[r][v] = columns[c][v] = squares[get_square_idx(r, c)][v] = 1;
                }
            }
        }
        
        function<bool(int)> backtrack;
        backtrack = [&](int empty_cell_idx) {
            if (empty_cell_idx == size(empty_cells)) {
                return true;
            }
            const auto[i, j] = empty_cells[empty_cell_idx];
            const int sq_idx = get_square_idx(i, j);
            for (int v = 1; v <= n; ++v) {
                if (!rows[i][v] && !columns[j][v] && !squares[sq_idx][v]) {
                    rows[i][v] = columns[j][v] = squares[sq_idx][v] = 1;
                    board[i][j] = v + '0';
                    if (backtrack(empty_cell_idx + 1)) {
                        return true;
                    }
                    rows[i][v] = columns[j][v] = squares[sq_idx][v] = 0;
                }
            }
            return false;
        };
        backtrack(0);
    }
};