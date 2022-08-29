class Solution {
    bool check(string& s, string& p) {
        auto sIndex{0};
        auto pIndex{0};
        while (sIndex < s.size() && pIndex < p.size()) {
            if (s[sIndex] == p[pIndex]) {
                ++sIndex;
                ++pIndex;
            } else {
                ++sIndex;
            }
        }
        
        auto count{0};
        for (auto i = 0; i < max(s.size(), p.size()); ++i) {
            if (i < s.size() && isupper(s[i])) ++count;
            if (i < p.size() && isupper(p[i])) --count;
        }
        
        return pIndex == p.size() && count == 0;
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (auto i : queries) {
            ans.push_back(check(i, pattern));
        }
        return ans;
    }
};