class Solution {
public:
    bool checkPartitioning(string s) {
        auto n{static_cast<int>(s.size())};
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        for (auto i = n-1; i >= 0; --i) {
            for (auto j = n; j >= 0; --j) {
                // cout << i << " " << j << "\n";
                if (i >= j) dp[i][j] = true;
                else if (abs(i - j) <= 1) dp[i][j] = true;
                else dp[i][j] = (s[i] == s[j-1]) && dp[i+1][j-1];
                // if (j > i && dp[i][j]) cout << s.substr(i, j-i) << "\n";
                // if (j > i && dp[i][j]) cout << "[" << i << "," << j << ")\n";
            }
        }
        
        // first interval from [0, left)
        // second interval from [left, right)
        // third interval from [right, n)
        for (auto i = 1; i < n; ++i) {
            if (dp[0][i]) {
                for (auto j = i+1; j < n; ++j) {
                    // cout << i << " " << j << " " << j << " " << n+1 << "\n";
                    if (dp[i][j] && dp[j][n]) return true; // n = 5
                }
            }
        }
        // cout << dp[0][1] << " " << dp[1][2] << " " << dp[2][5] << "\n";
        // for (auto i : dp) {
        //     for (auto j : i) {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        // dp[i][i] = false
        // dp[i][i+1] = true
        // dp[i][i+2] = true if s[i] == s[i+1]
        // dp[i][j] = if (s[i] == s[j-1]) && dp[i+1][j-2]
        return false;
    }
};
// "juchzcedhfesefhdeczhcujzzvbmoeombv"
// "bpomo"