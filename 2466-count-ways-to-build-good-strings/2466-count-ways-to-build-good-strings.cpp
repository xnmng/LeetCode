// https://youtu.be/JKpVHG2mhbk
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        auto modulo{static_cast<int>(1e9+7)};
        vector<int> dp(high+1, 0);
        auto ans{0};
        dp[0] = 1;
        for (auto i = 1; i < dp.size(); ++i) {
            if (i - one >= 0) dp[i] = (dp[i] + dp[i-one]) % modulo;
            if (i - zero >= 0) dp[i] = (dp[i] + dp[i-zero]) % modulo;
            if (i >= low) ans = (ans + dp[i]) % modulo;
        }
        return ans;
    }
};