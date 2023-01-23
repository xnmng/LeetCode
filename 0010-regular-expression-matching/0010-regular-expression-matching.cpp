class Solution {
public:
    bool isMatch(string s, string regex) {
        auto m{s.size()};
        auto n{regex.size()};
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        for (auto i = 0; i <= m; ++i) {
            for (auto j = 0; j <= n; ++j) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (i == 0) {
                    if (regex[j-1] == '*') {
                        dp[i][j] = dp[i][j-2];
                    }
                }
                else if (j > 0) {
                    if (regex[j-1] == '*') {
                        dp[i][j] = dp[i][j-2];
                        if (regex[j-2] == '.' || regex[j-2] == s[i-1]) {
                            dp[i][j] = dp[i][j] || dp[i-1][j];        
                        }
                    }
                    else {
                        dp[i][j] = dp[i-1][j-1] && (regex[j-1] == '.' || regex[j-1] == s[i-1]);
                    }
                }
            }
        }
        return dp.back().back();
    }
};