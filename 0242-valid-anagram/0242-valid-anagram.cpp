class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,int> mp;
        for (char c : s) {
            ++mp[c];
        }
        for (char c : t) {
            --mp[c];
            // pigeonhole principle
            if (mp[c] < 0) return false;
        }
        // for (auto& [k,v] : mp) {
            // if (v != 0) return false;
        // }
        return true;
    }
};