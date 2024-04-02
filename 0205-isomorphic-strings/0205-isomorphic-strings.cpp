class Solution {
public:
    // check for mapping contradictions using umap
    // use a set to check for scenario two chars map to the same char
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mapping;
        unordered_set<char> isUsed;
        for (auto i = 0; i < s.size(); ++i) {
            if (mapping.find(s[i]) == mapping.end()) {
                mapping[s[i]] = t[i];
                if (isUsed.find(t[i]) != isUsed.end()) return false;
                isUsed.insert(t[i]);
            } else if (mapping[s[i]] != t[i]) return false;
        }
        return true;
    }
};
// "13"
// "42"
// "badc"
// "baba"