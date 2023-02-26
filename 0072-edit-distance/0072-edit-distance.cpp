// https://youtu.be/XYi2-LPrwm4
// https://leetcode.com/problems/edit-distance/discuss/25846/C++-O(n)-space-DP
class Solution {
public:
    int minDistance(string word1, string word2) {
        auto m{static_cast<int>(word1.size())};
        auto n{static_cast<int>(word2.size())};
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        for (auto i = 0; i < m+1; ++i) {
            dp[i][n] = m - i;
        }
        for (auto i = 0; i < n+1; ++i) {
            dp[m][i] = n - i;
        } 
        for (auto i = m-1; i >= 0; --i) {
            for (auto j = n-1; j >= 0; --j) {
                if (word1[i] == word2[j]) dp[i][j] = dp[i+1][j+1];
                else {
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1]);
                    dp[i][j] = min(dp[i][j], 1 + dp[i+1][j+1]);
                }
            }
        }
        // for (auto i : dp) {
        //     for (auto j : i) {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        return dp.front().front();
    }
};