// dp[i][j] := does the string from [0..i] and pattern from [0..j], match?

// dp[0][0] = true
// dp[i][0] = true only if p[0] == *

// if p[j] == '.', dp[i][j] = dp[i-1][j-1]
// if p[j] == s[i], dp[i][j] = dp[i-1][j-1]
// if p[j] == '*', dp[i][j] = dp[i-1][j] || dp[i][j-1]

// https://leetcode.com/problems/wildcard-matching/discuss/1001130/C++-Clean-and-concise-bottom-up-dp-code-with-detailed-explanation-easy-to-understand.
class Solution {
public:
    bool isMatch(string s, string p) {
        auto m{s.size()};
        auto n{p.size()};
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0] = true;
        for (auto i = 1; i <= n && p[i-1] == '*'; ++i) {
            dp[0][i] = dp[0][i-1];
        }

        for (auto i = 1; i <= m; ++i) {
            for (auto j = 1; j <= n; ++j) {
                if (p[j-1] == '?' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        
        return dp.back().back();
    }
};

//"adceb"
// "*a*b"
// ""
// "b*"