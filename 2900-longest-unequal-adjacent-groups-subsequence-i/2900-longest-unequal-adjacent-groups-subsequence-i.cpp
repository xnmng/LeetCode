class Solution {
public:
    // groups[i] is either 0 or 1!
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans{words[0]};
        int n = words.size();
        ans.reserve(n);
        for (int i = 1; i < n; ++i) {
            if (groups[i] != groups[i-1]) ans.emplace_back(words[i]);
        }
        return ans;
    }
};