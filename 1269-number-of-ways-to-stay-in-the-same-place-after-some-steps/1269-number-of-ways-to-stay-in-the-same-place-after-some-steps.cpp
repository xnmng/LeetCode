class Solution {
public:
    int numWays(int steps, int arrLen) {
        int modulo = 1e9 + 7;
        // if we have a maximum of k steps, we 
        int n = min(steps / 2 + 1, arrLen);
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (auto i = 0; i < steps; ++i) {
            vector<int> next(n, 0);
            for (auto j = 0; j < n; ++j) {
                if (j-1 >= 0) next[j-1] = (next[j-1] + dp[j]) % modulo;
                next[j] = (next[j] + dp[j]) % modulo;
                if (j+1 < n) next[j+1] = (next[j+1] + dp[j]) % modulo;
            }
            swap(dp, next);
        }
        return dp[0];
    }
};
// 438
// 315977