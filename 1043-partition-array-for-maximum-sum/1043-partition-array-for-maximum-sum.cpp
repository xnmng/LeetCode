// https://youtu.be/kWhy4ZUBdOY?si=gfq3Q4ElBTJDGi7N
class Solution {
public:
    // O(nk) time, O(k) space
    // (since we notice we only need the prev k values of dp)
    // circular array optimization (reduce space from O(n) to O(k), use mod k to circle around the dp arr)
    //
    // dp[i] records the maximum sum we can get considering A[0] ~ A[i-1]
    // To get dp[i], we will try to change k last numbers separately to the maximum of them,
    // where k = 1 to k = K.
    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     vector<int> dp(k, 0);
    //     dp[0] = arr[0]; // base case
    //     int n = arr.size();
    //     int curMax;     // store max element value encountered so far
    //     int indexMax;   // store result for dp[i]; max sum for this given index
    //     for (int i = 1; i < n; ++i) {
    //         indexMax = 0; // reset value at the start of this iteration
    //         curMax = 0; // reset value at the start of this iteration
    //         for (int j = 1; i <= k && i - j > 0; ++j) {
    //             curMax = max(curMax, arr[i - j]);
    //             indexMax = max(indexMax, curMax * j + dp[(i - j) % k]);
    //         }
    //         dp[i % k] = indexMax;
    //     }
    //     for (auto i : dp) cout << i << " ";
    //     return dp[(n-1) % k];
    // }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), 0);
        auto m{INT_MIN};
        for (auto i = 1; i <= k; ++i) {
            m = max(m, arr[i-1]);
            dp[i-1] = m * i;
        }
        for (auto i = k; i < arr.size(); ++i) {
            m = INT_MIN;
            for (auto j = 1; j <= k; ++j) {
                m = max(m, arr[i-j+1]);
                dp[i] = max(dp[i], m * j + dp[i-j]);
            }
        }
        // for (auto i : dp) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        return dp.back();
    }
};
                    
             