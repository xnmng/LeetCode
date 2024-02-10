class Solution {
public:
    // TODO: manacher's algorithm
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ans += count(s, i, i);
            ans += count(s, i-1, i);
        }
        return ans;
    }
    
    int count(string& s, int left, int right) {
        if (left < 0 || right >= s.size()) return 0;
        if (s[left] != s[right]) return 0;
        return 1 + count(s, left-1, right+1);
    }
};