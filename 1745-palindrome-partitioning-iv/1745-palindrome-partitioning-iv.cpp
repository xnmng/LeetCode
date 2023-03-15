class Solution {
public:
    bool checkPartitioning(string s) {
        auto n{static_cast<int>(s.size())};
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        for (auto i = n-1; i >= 0; --i) {
            for (auto j = n; j >= 0; --j) {
                if (i >= j) dp[i][j] = true;
                else if (abs(i - j) <= 1) dp[i][j] = true;
                else dp[i][j] = (s[i] == s[j-1]) && dp[i+1][j-1];
            }
        }
        
        // first interval from [0, left)
        // second interval from [left, right)
        // third interval from [right, n)
        for (auto i = 1; i < n; ++i) {
            if (dp[0][i]) {
                for (auto j = i+1; j < n; ++j) {
                    if (dp[i][j] && dp[j][n]) return true; // n = 5
                }
            }
        }
        return false;
    }
};
// "juchzcedhfesefhdeczhcujzzvbmoeombv"
// "bpomo"