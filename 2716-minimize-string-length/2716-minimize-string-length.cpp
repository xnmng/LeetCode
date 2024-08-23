class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> uset(s.begin(), s.end());
        return uset.size();
    }
};