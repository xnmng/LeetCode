class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        for (string& s : words) {
            if (!ans.empty() && helper(ans.back(), s)) {
                continue;
            }
            ans.emplace_back(s);
        }
        return ans;
    }

    bool helper(string& s1, string& s2) {
        vector<int> s(26, 0);
        for (char c : s1) ++s[c - 'a'];
        for (char c : s2) --s[c - 'a'];
        for (int i : s) if (i != 0) return false;
        return true;
    }
};