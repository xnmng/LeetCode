// https://leetcode.com/problems/unique-binary-search-trees/discuss/1565543/C++Python-5-Easy-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Catalan-O(N)
class Solution {
private:
    int dfs(int n, vector<int>& dp) {
        if (dp[n] == INT_MAX) {
            dp[n] = 0;
            for (auto i = 0; i < n; ++i) {
                dp[n] += dfs(i, dp) * dfs(n-1-i, dp);
            }
        }
        return dp[n];
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 1;
        dp[1] = 1;
        dfs(n, dp);
        // for (auto i : dp) cout << i << " ";
        // cout << "\n";
        return dfs(n, dp);
    }
};