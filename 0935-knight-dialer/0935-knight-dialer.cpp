class Solution {
private:
    int dfs(int n, int cur, vector<vector<int>>& dp, unordered_map<int, vector<int>>& next) {
        auto modulo{static_cast<int>(1e9 + 7)};
        auto ans{0};
        if (n == 0) return 1;
        if (dp[n][cur] == -1) {
            for (auto& i : next[cur]) {
                // cout << i << " ";
                ans = (ans + dfs(n-1, i, dp, next)) % modulo;
            }
            dp[n][cur] = ans;
        }
        return dp[n][cur];
    }
public:
    int knightDialer(int n) {
        auto modulo{static_cast<int>(1e9 + 7)};
        unordered_map<int, vector<int>> next{
            {0, {4, 6}},
            {1, {6, 8}},
            {2, {7, 9}},
            {3, {4, 8}},
            {4, {0, 3, 9}},
            {5, {}},
            {6, {0, 1, 7}},
            {7, {2, 6}},
            {8, {1, 3}},
            {9, {2, 4}},
        };
        auto ans{0};
        vector<vector<int>> dp(n, vector<int>(10, -1));
        for (auto& [k, v] : next) {
            // cout << k << "\n";
            // cout << k << " ";
            ans = (ans + dfs(n-1, k, dp, next)) % modulo;
            // cout << k << " ok\n";
            // cout << "\n";
        }
        return ans;
    }
};