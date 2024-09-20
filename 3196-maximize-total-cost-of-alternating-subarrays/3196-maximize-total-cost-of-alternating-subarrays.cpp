class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        // dp[0] (positive)
        // dp[1] (negative)
        vector<vector<long long>> dp(2, vector<long long>(n, INT_MIN));
        // if (nums[0] > 0) {
            dp[0][0] = nums[0];
            dp[1][0] = nums[0];
        // } 
        // else {
        //     dp[0][0] = nums[0];
        //     dp[1][0] = nums[0];            
        // }
        for (int i = 1; i < n; ++i) {
            // if (nums[i] > 0) {
            //     dp[0][i] = max(dp[0][i-1], dp[1][i-1]) + nums[i];
            //     dp[1][i] = dp[0][i];
            // }
            // else {
                dp[0][i] = dp[1][i-1] - nums[i];
                dp[1][i] = max(dp[0][i-1], dp[1][i-1]) + nums[i];
            // }
        }
        // for (auto i : dp) {
        //     for (auto j : i) {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        return max(dp[0].back(), dp[1].back());
    }
};
// [4,-5,-3,-2,-4,4]



// 4 -5 -3 -2 -4

// 4  9  2  8  4 8 
// 4 -1  6  0  4 8 