class Solution {
public:
    // bottom up dp, O(n) space
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        // sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, 0);
        for (int& i : coins) {
            if (i >= dp.size()) continue;
            ++dp[i];
            for (int j = i; j < dp.size(); ++j) {
                dp[j] += dp[j - i];
            }
        }
        // for (auto i : dp) cout << i << " ";
        // cout << "\n";
        return dp[amount];
    }
};
// 0
// [7]
// 5
// [1,2,5]