class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        auto n{word1.size()};
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for (auto i = 0; i < n; ++i) {
            ++mp1[word1[i]];
            ++mp2[word2[i]];
        }
        unordered_map<int,int> mp;
        unordered_set<char> s;
        for (auto& [k,v] : mp1) {
            ++mp[v];
            s.insert(k);
        }
        for (auto& [k,v] : mp2) {
            --mp[v];
            if (s.insert(k).second) return false;
        }
        for (auto& [k,v] : mp) {
            if (v != 0) return false;
        }
        return true;
    }
};