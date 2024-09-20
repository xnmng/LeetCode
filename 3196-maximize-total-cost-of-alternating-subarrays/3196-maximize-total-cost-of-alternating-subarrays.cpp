class Solution {
public:
    // if we encounter a positive element, we should definitely put it in its own subarray
    // placing it at the end of some subarray might cause it to contribute negative cost to our resulting answer,
    // counterproductive since our goal is to maximize the cost
    //
    // if we encounter a negative element, we have an option to make:
    // add to some previous subarray (performing the math)
    // start it as some previous subarray 
    // (as perhaps some element down the road should be positive by cost function formula)
    // (e.g. [-1, -1000], we want -1 to be positive, so we can flip the sign of -1000)
    //
    // notice that for the positive element, since it should be in its own subarray, it acts as a 'checkpoint';
    // we should just take the max of previous choices and add this positive value to it
    //
    // hence we arrive at our recurrence relation:
    // let dp[0][i] indicate we multiplied nums[i] with -1
    // let dp[1][i] indicate we multiplied nums[i] with 1
    // base case:
    //      (for base case, single element is its own subarray, so its cost is just its own value)
    //      dp[0][0] = dp[1][0] = nums[0]
    // recurrence:
    //      dp[0][i] = dp[1][i-1] - nums[i] 
    //          (since we are taking this index * -1, it must have been because we had some positive index prior)
    //      dp[1][i] = max(dp[0][i-1], dp[1][i-1]) + nums[i]
    //          (since we are taking this index * 1, we just take the max of previous index's choices)
    //
    // O(n) time, O(1) space (see recurrence)
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        long long positive = nums[0];
        long long negative = nums[0];
        long long positiveNext;
        long long negativeNext;
        
        for (int i = 1; i < n; ++i) {
            negativeNext = positive - nums[i];
            positiveNext = max(positive, negative) + nums[i];
            positive = positiveNext;
            negative = negativeNext;
        }
        
        return max(positive, negative);
    }
    
//     // O(n) time, O(n) space (possible to reduce to O(1) space due to recurrence) 
//     long long maximumTotalCost(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<long long>> dp(2, vector<long long>(n, INT_MIN));
//         dp[0][0] = nums[0];
//         dp[1][0] = nums[0];
        
//         for (int i = 1; i < n; ++i) {
//             dp[0][i] = dp[1][i-1] - nums[i];
//             dp[1][i] = max(dp[0][i-1], dp[1][i-1]) + nums[i];
//         }
        
//         return max(dp[0].back(), dp[1].back());
//     }
};
// [4,-5,-3,-2,-4,4]