// https://leetcode.com/problems/extra-characters-in-a-string/solution/
class Solution {
public:
    // TODO: optimize using trie
    // O(n^3) time, O(n + mk) space
    //
    // n input, each input check n substr start positions, n substrings created, 
    // dp arr size n, dict arr size k, each word in dict size m
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        int val;
        unordered_set<string> uset(dictionary.begin(), dictionary.end());
        for (auto i = n-1; i >= 0; --i) {
            dp[i] = dp[i+1] + 1; // base case; this cur letter is extra
            for (auto j = i; j < n; ++j) {
                if (uset.find(s.substr(i, j-i+1)) != uset.end()) {
                    dp[i] = min(dp[i], dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};
