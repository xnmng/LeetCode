class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long modulo = 1e9 + 7;
        vector<long long> dp(forget, 0);
        vector<long long> next(forget, 0);
        dp[0] = 1;
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < forget - 1; ++j) {
                if (j >= delay - 1) {
                    next[j+1] = (next[j+1] + dp[j]) % modulo;
                    next[0] = (next[0] + dp[j]) % modulo;
                }
                else {
                    next[j+1] = dp[j];
                }
            }
            swap(dp, next);
            fill(next.begin(), next.end(), 0);
            // next = vector<int>(forget, 0);
            // for (int i : dp) cout << i << " ";
            // cout << "\n";
        }
        long long ans = 0;
        for (int i = 0; i < forget; ++i) {
            ans = (ans + dp[i]) % modulo;
        }
        return ans;
    }
};