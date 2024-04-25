class Solution {
public:
    int longestIdealString(string s, int k) {
        // if (k == 25) return s.size();
        vector<int> dp(26, 0); // longest ideal string ending at this char
        int ans = 0;
        // for (auto c = 0; c < 26; ++c) cout << (char)('a' + c) << " ";
        // cout << "\n";
        for (char c : s) {
            vector<int> temp = dp;
            for (int i = 0; i <= k; ++i) {
                if (c - 'a' - i >= 0) temp[c - 'a'] = max(temp[c - 'a'], 1 + dp[c - 'a' - i]);
                if (c - 'a' + i < 26) temp[c - 'a'] = max(temp[c - 'a'], 1 + dp[c - 'a' + i]);
            }
            swap(temp, dp);
            ans = max(ans, dp[c - 'a']);
            // for (auto i : dp) cout << i << " ";
            // cout << "\n";
        }
        return ans;
    }
};
// "azaza"
// 25
// "zjhngjkfv"
// 21