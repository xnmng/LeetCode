// https://leetcode.com/problems/jump-game-vii/discuss/1226593/Two-Pointers-and-Sliding-Window
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        auto count{0};
        auto n{s.size()};
        vector<bool> dp(n, false);
        dp[0] = true;
        for (auto i = 1; i < n; ++i) {
            if (i >= minJump) count += dp[i - minJump];
            if (i > maxJump) count -= dp[i - maxJump - 1];
            dp[i] = count > 0 && s[i] == '0';
        }
        return dp.back();
    }
};