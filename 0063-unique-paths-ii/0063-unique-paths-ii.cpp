class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m{static_cast<int>(obstacleGrid.size())};
        int n{static_cast<int>(obstacleGrid[0].size())};
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (obstacleGrid[0][0] != 1) dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                if (i > 0) dp[i][j] += dp[i-1][j];
                if (j > 0) dp[i][j] += dp[i][j-1];
            }
        }
        return dp.back().back();
    }
};
// [[1]]