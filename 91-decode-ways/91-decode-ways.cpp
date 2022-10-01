// https://youtu.be/6aEyTjOwlJU
// https://leetcode.com/problems/decode-ways/discuss/1410794/C++Python-From-Top-down-DP-to-Bottom-up-DP-O(1)-Space-Clean-and-Concise
class Solution {
    // dp[i] = dp[i+1] + dp[i+2] (only if digit and double digit are valid respectively)
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        
        auto i{static_cast<int>(s.size()-1)};
        auto dp{0};
        auto dp1{1};
        auto dp2{0};
        
        while (i >= 0) {
            dp = 0;
            if (s[i] != '0') {
                dp += dp1;
            }
            if (i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
                dp += dp2;
            }
                
            --i;
            dp2 = dp1;
            dp1 = dp;
        }
        return dp;
    }
};