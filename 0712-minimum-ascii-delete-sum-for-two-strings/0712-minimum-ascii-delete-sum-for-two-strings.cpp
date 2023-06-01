class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        auto m{static_cast<int>(s1.size())};
        auto n{static_cast<int>(s2.size())};
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // remember to initialize the edge cases carefully!
        for (auto i = m-1; i >= 0; --i) {
            dp[i][n] = dp[i+1][n] + (int) s1[i];    
        }
        for (auto j = n-1; j >= 0; --j) {
            dp[m][j] = dp[m][j+1] + (int) s2[j];    
        }
        
        for (auto i = m-1; i >= 0; --i) {
            for (auto j = n-1; j >= 0; --j) {
                if (s1[i] == s2[j]) dp[i][j] = dp[i+1][j+1];
                else {
                    dp[i][j] = min((int) s1[i] + dp[i+1][j], (int) s2[j] + dp[i][j+1]);
                }
            }
        }
        
        // for (auto i : dp) {
        //     for (auto j : i) {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        return dp.front().front();
    }
};
