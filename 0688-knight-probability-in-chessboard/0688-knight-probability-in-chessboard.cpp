class Solution {
public:
    // (+- 2, +- 1) or (+- 1, +- 2)
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 0));
        dp[row][column] = 1;
        while (k > 0) {
            --k;
            vector<vector<double>> next(n, vector<double>(n, 0));
            for (auto i = 0; i < n; ++i) {
                for (auto j = 0; j < n; ++j) {
                    if (dp[i][j] > 0) {
                        if (i + 2 < n && j + 1 < n) next[i+2][j+1] += dp[i][j] / 8;
                        if (i + 2 < n && j - 1 >= 0) next[i+2][j-1] += dp[i][j] / 8;
                        if (i - 2 >= 0 && j + 1 < n) next[i-2][j+1] += dp[i][j] / 8;
                        if (i - 2 >= 0 && j - 1 >= 0) next[i-2][j-1] += dp[i][j] / 8;                         
                        if (i + 1 < n && j + 2 < n) next[i+1][j+2] += dp[i][j] / 8;
                        if (i + 1 < n && j - 2 >= 0) next[i+1][j-2] += dp[i][j] / 8;
                        if (i - 1 >= 0 && j + 2 < n) next[i-1][j+2] += dp[i][j] / 8;
                        if (i - 1 >= 0 && j - 2 >= 0) next[i-1][j-2] += dp[i][j] / 8;   
                    }
                }
            }
            swap(dp, next);
        }
        auto ans{0.0};
        for (auto& i : dp) {
            for (auto& j : i) {
                ans += j;
            }
        }
        return ans;
    }
};
// 3
// 1
// 1
// 1