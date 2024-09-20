class Solution {
public:
    // TODO: space optimize this to O(1) space (see recurrence)
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        // dp[0] (positive)
        // dp[1] (negative)
        vector<vector<long long>> dp(2, vector<long long>(n, INT_MIN));
        dp[0][0] = nums[0];
        dp[1][0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[1][i-1] - nums[i];
            dp[1][i] = max(dp[0][i-1], dp[1][i-1]) + nums[i];
        }
        return max(dp[0].back(), dp[1].back());
    }
};
// [4,-5,-3,-2,-4,4]