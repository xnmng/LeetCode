class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int a = 0; // all rows
        int b = 0; // all cols
        int m = grid.size();
        int n = grid[0].size();
        for (auto i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // cout << "a " << i << " " << j << " " << n - j - 1 << "\n";
                if (grid[i][j] != grid[i][n - j - 1] && j != n - j - 1) {
                    ++a;
                }
                // cout << "b " << i << " " << j << " " << m - i - 1 << "\n";
                if (grid[i][j] != grid[m - i - 1][j] && i != m - i - 1) {
                     ++b;
                }
            }
        }
        return min(a/2, b/2);
    }
};