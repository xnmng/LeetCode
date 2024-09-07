class Solution {
public:
    // https://leetcode.com/problems/construct-k-palindrome-strings/discuss/563379/JavaC++Python-Straight-Forward
    //
    // to ensure that each of the k strings is non-empty,
    // we require k <= s.size()
    //
    // we also need the number of odd chars to be less than or equal to k
    // for a char c, if it has a odd char (2k + 1), 
    // the 1 has to be in the middle of a palindrome for a valid soln
    bool canConstruct(string s, int k) {
        if (k > s.size()) return false;
        int oddCount = 0;
        vector<bool> v(26, false);
        for (char c : s) {
            // flip the bit using XOR
            // false -> true -> false -> ...
            v[c - 'a'] = v[c - 'a'] ^ true;
            if (v[c - 'a'] % 2 == 0) {
                --oddCount;
            }
            else {
                ++oddCount;
            }
        }
        return oddCount <= k;
    }
};