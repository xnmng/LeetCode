class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<long long> dp(n, INT_MIN);
        // for (int j = 0; j < n; ++j) {
        //     dp[j] = a[0] * b[j];
        //     if (j > 0) {
        //         dp[j] = max(dp[j], dp[j-1]);
        //     }
        // }

        // for (int i : dp) {
        //     cout << i << " ";
        // }
        // cout << "\n";

        for (int i = 0; i < 4; ++i) {
            vector<long long> next(n, INT_MIN);
            for (int j = i; j < n; ++j) {
                next[j] = (long long) a[i] * b[j] + (i > 0 ? dp[j-1] : 0);
                if (j > 0) {
                    next[j] = max(next[j], next[j-1]);
                }
            }
            swap(dp, next);
            // for (int i : dp) {
            //     cout << i << " ";
            // }
            // cout << "\n";
        }

        return dp.back();
    }
};