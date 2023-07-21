class Solution {
public:
    // dp solution, O(n^2) time
    int lengthOfLIS(vector<int>& nums) {
        auto n{nums.size()};
        vector<int> dp(n);
        auto ans{0};
        for (auto i = 0; i < n; ++i) {
            dp[i] = 1;
            for (auto j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};