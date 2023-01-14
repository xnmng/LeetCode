class Solution {
    string commonPrefix(string& s1, string& s2) {
        string ans{""};
        for (auto i = 0; i < min(s1.size(), s2.size()); ++i) {
            if (s1[i] == s2[i]) ans.push_back(s1[i]);
            else return ans;
        }
        return ans;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto ans{strs[0]};
        for (auto i = 1; i < strs.size(); ++i) {
            ans = commonPrefix(ans, strs[i]);
        }
        return ans;
    }
};