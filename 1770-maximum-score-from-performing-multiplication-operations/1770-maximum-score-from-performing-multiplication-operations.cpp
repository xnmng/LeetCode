class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        auto m {static_cast<int>(multipliers.size())};
        auto n {static_cast<int>(nums.size())};
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0)); // [index][left]
        
        for (auto i = m-1; i >= 0; --i) {
            for (auto j = i; j >= 0; --j) {
                dp[i][j] = max(multipliers[i] * nums[j] + dp[i + 1][j + 1],
                                   multipliers[i] * nums[n - 1 - (i - j)] + dp[i + 1][j]);
            }
        }
        
        return dp[0][0];
    }
};