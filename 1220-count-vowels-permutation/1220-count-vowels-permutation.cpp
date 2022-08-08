class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n, vector<long long>(5,0));
        auto modulo = 1000000007;
        for (auto i = 0; i < 5; ++i) {
            dp[0][i] = 1;
        }
        for (auto i = 1; i < dp.size(); ++i) {
            dp[i][0] += dp[i-1][1] + dp[i-1][2] + dp[i-1][4];
            dp[i][1] += dp[i-1][0] + dp[i-1][2];
            dp[i][2] += dp[i-1][1] + dp[i-1][3];
            dp[i][3] += dp[i-1][2];
            dp[i][4] += dp[i-1][2] + dp[i-1][3];
            
            dp[i][0] %= modulo;
            dp[i][1] %= modulo;
            dp[i][2] %= modulo;
            dp[i][3] %= modulo;
            dp[i][4] %= modulo;
        }
        
        auto ans = 0;
        for (auto i = 0; i < 5; ++i) {
            ans += dp[n-1][i];
            ans %= modulo;
        }        
        
        return ans;
    }
};