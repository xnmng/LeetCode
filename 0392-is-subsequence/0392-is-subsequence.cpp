class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = 0;
        int n = 0;
        while (n < t.size() && m < s.size()) {
            if (s[m] == t[n]) {
                ++m;
            }
            ++n;
        }
        return m == s.size();
    }
};