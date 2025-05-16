class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1); // dp[i] := if we use words[i] whats the longest ss?
        vector<int> prev(n, -1); // prev[i] := given dp[i], what was the prev element in this longest ss?

        int index = 0; // index of the end of our longest ss
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] 
                    && helper(words[i], words[j]) 
                    && dp[j] + 1 > dp[i]) { // only consider ss that improve our answer
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[index]) {
                index = i;
            }
        }

        vector<string> ans;
        while (index != -1) {
            ans.emplace_back(words[index]);
            index = prev[index];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool helper(string& a, string& b) {
        int n = a.size();
        if (n != b.size()) return false;
        bool ans = true; // 2 strikes and youre out
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                if (!ans) return false;
                ans = false;
            }
        }
        return true;
    }
};