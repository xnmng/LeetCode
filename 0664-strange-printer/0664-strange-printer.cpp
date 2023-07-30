// https://leetcode.com/problems/strange-printer/discuss/106794/One-suggestion-for-all-solutions
class Solution {
private:
    // same answer but less input to process
    string preprocess(string s) {
        string ans{""};
        for (auto i : s) {
            if (ans.empty() || ans.back() != i) ans += i;
        }
        return ans;
    }
    
    // s[left, right]
    int dfs(string& s, vector<vector<int>>& dp, int left, int right) {
        if (left > right) return dfs(s, dp, right, right);
        if (dp[left][right] == INT_MAX) {
            // leftmost index char that differs from s[right]
            // e.g. s = "abcda" left = 0, right = 4
            int prev{-1};
            for (auto i = left; i < right; ++i) {
                if (s[i] != s[right] && prev == -1) prev = i;
                if (prev != -1) {
                    dp[left][right] = min(dp[left][right],
                                         1 + dfs(s, dp, prev, i) + dfs(s, dp, i+1, right));
                }
            }
            if (prev == -1) dp[left][right] = 0;
        }
        return dp[left][right];
    }
public:
    int strangePrinter(string s) {
        s = preprocess(s);
        auto n{s.size()};
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dfs(s, dp, 0, n-1);
        // for (auto i : dp) {
        //     for (auto j : i) cout << j << " ";
        //     cout << "\n";
        // }
        return 1 + dfs(s, dp, 0, n-1); // +1 to factor in initial print
    }
};