class Solution {
public:
    // TODO: manacher's algorithm O(n) time solution to this problem
    //
    // check each 'core', dont recompute same subproblem
    // O(n^2) time, O(n) space (due to recursion max depth being entire len of string)
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
        return 1 + count(s, left-1, right+1); // tail recursion optimization
    }
};