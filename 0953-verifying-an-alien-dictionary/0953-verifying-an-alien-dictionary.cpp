class Solution {
private:
    // true if s2 is after s1 in dict
    // false otherwise
    bool helper(string& s1, string& s2, unordered_map<char,int>& mp) {
        for (auto i = 0; i < min(s1.size(), s2.size()); ++i) {
            if (mp[s1[i]] == mp[s2[i]]) {
                continue;
            }
            if (mp[s1[i]] > mp[s2[i]]) {
                // cout << s1[i] << " is after " << s2[i] << "\n";
                return false;
            }
            if (mp[s1[i]] < mp[s2[i]]) {
                // cout << s1[i] << " is before " << s2[i] << "\n";
                return true;
            }
        }
        return s2.size() < s1.size() ? false : true;
    }
    
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for (auto i = 0; i < order.size(); ++i) {
            mp[order[i]] = i;
        }
        for (auto i = 1; i < words.size(); ++i) {
            if (!helper(words[i-1], words[i], mp)) return false;
        }
        return true;
    }
};