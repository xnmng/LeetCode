class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
        auto modulo{static_cast<int>(1e9 + 7)};
        // default path with length 1 (grid[i][j] itself) is strictly increasing
        auto ans{1};
        if (dp[i][j] == -1) {
            if (i+1 < grid.size() && grid[i][j] < grid[i+1][j]) ans = (ans + dfs(grid, dp, i+1, j)) % modulo;
            if (j+1 < grid[0].size() && grid[i][j] < grid[i][j+1]) ans = (ans + dfs(grid, dp, i, j+1)) % modulo;
            if (i-1 >= 0 && grid[i][j] < grid[i-1][j]) ans = (ans + dfs(grid, dp, i-1, j)) % modulo;
            if (j-1 >= 0 && grid[i][j] < grid[i][j-1]) ans = (ans + dfs(grid, dp, i, j-1)) % modulo;
            dp[i][j] = ans;
        }
        return dp[i][j];
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        auto modulo{static_cast<int>(1e9 + 7)};
        auto m{grid.size()};
        auto n{grid[0].size()};
        auto ans{0};
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                ans = (dfs(grid, dp, i, j) + ans) % modulo;
            }
        }
        return ans;
    }
};
