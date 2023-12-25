class Solution {
public:
    // https://leetcode.com/problems/decode-ways/discuss/30451/Evolve-from-recursion-to-dp
    // if dont understand this, start from recursive w memo solution
    int numDecodings(string s) {
        if (s.front() == '0') return 0;
        
        int n = s.size();
        int cur = 0;
        int prev = 1; // base case; empty string has 1 way to decode it
        int prevprev = 0; // doesnt matter since this will not be used for small sized test cases
        
        for (int i = n - 1; i >= 0; --i) {
            // check the case where the number is decoded by itself
            cur = s[i] == '0' ? 0 : prev;
            
            // check the case where the number is decoded with the next number
            if (s[i] == '1' 
                || (i+1 < n && s[i] == '2' && s[i+1] < '7')) cur += prevprev;
            
            // update the prev and prevprev values (for the next iteration)
            prevprev = prev;
            prev = cur;
        }
        
        return cur;
    }
};

/*
// https://youtu.be/6aEyTjOwlJU
// https://leetcode.com/problems/decode-ways/discuss/1410794/C++Python-From-Top-down-DP-to-Bottom-up-DP-O(1)-Space-Clean-and-Concise
class Solution {
    // dp[i] = dp[i+1] + dp[i+2] (only if digit and double digit are valid respectively, else dp[i+2] = 0)
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
            if (i+1 < s.size() 
                && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
                dp += dp2;
            }  
            --i;
            dp2 = dp1;
            dp1 = dp;
        }
        return dp;
    }
};

*/