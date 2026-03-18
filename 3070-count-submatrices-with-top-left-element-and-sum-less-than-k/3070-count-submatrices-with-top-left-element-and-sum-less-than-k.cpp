class Solution {
public:
    // count using inclusion exclusion principle
    // dp[i][j] stores the submatrix with 
    // top-left at (0,0) and bottom-right at (i,j)
    // O(mn) time, O(mn) space (if reuse input, O(1) space) 
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) grid[i][j] += grid[i-1][j];
                if (j > 0) grid[i][j] += grid[i][j-1];
                if (i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
                if (grid[i][j] <= k) {
                    ++ans;
                    // cout << i << " " << j << "\n";
                }
            }
        }
        // for (auto i : grid) {
        //     for (auto j : i) cout << j << " ";
        //     cout << "\n";
        // }
        return ans;
    }
};