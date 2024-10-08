class Solution {
public:
    // dp[1] = 1, dp[2] = 2
    // dp[i] = dp[i-1] + dp[i-2];
    //
    // O(n) time, O(1) space approach
    int climbStairs(int n) {
        if (n < 3) return n;
        auto count{3};
        auto cur{3};
        auto prev{3};
        auto prevprev{2};
        while (count < n) {
            ++count;
            cur = prev + prevprev;
            prevprev = prev;
            prev = cur;
        }
        return cur;
    }
};