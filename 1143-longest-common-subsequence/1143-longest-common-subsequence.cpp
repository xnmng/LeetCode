// https://youtu.be/Ua0GhsJSlWM
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        auto m{static_cast<int>(text1.size())};
        auto n{static_cast<int>(text2.size())};
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (auto i = m-1; i >= 0; --i) {
            for (auto j = n-1; j >= 0; --j) {
                if (text1[i] == text2[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        // for (auto i : dp) {
        //     for (auto j : i) {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        return dp[0][0];
    }
};
// "bsbininm"
// "jmjkbkjkv"