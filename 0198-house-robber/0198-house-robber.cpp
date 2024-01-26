class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int prevprev = 0;
        int prev = nums[0];
        int cur;
        for (int i = 1; i < n; ++i) {
            cur = max(prev, prevprev + nums[i]);
            prevprev = prev;
            prev = cur;
        }
        return cur;
    }

    // can optimize to O(1) space; just store prev and prevprev state, update at every iteration
    // int rob(vector<int>& nums) {
    //     vector<int> dp(nums.size());
    //     dp[0] = nums[0];
    //     if (nums.size() > 1) dp[1] = max(dp[0], nums[1]);
    //     for (auto i = 2; i < nums.size(); ++i) {
    //         dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    //     }
    //     return dp.back();
    // }
};