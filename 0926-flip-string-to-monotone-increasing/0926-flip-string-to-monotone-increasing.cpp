class Solution {
public:
    int minFlipsMonoIncr(string s) {
        /*
            dp[0][i] := cost to make 0...0
            dp[1][i] := cost to make X...1
            
            you can use the 0 sequence to make 1, 
            but not the other way around
            (i.e. you might get 0...1...0, which is wrong)
        */
        vector<vector<int>> dp(2, vector<int>(s.size(), INT_MAX));
        dp[0][0] = s[0] != '0';
        dp[1][0] = s[0] != '1';
        for (auto i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                dp[0][i] = dp[0][i-1];
                dp[1][i] = min(1 + dp[1][i-1], 1 + dp[0][i-1]);
            } 
            else {
                dp[0][i] = 1 + dp[0][i-1];
                dp[1][i] = min(dp[1][i-1], dp[0][i-1]);
            }
        }
        // for (auto i : dp[0]) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        // for (auto i : dp[1]) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        return min(dp[0].back(), dp[1].back());
    }
};

// "010101"