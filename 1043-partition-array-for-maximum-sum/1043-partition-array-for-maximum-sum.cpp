class Solution {
public:
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
                    
             