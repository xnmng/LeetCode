class Solution {
public:
    // https://leetcode.com/problems/number-of-unique-good-subsequences/discuss/1432051/DP-O(n)-or-O(1)
    // https://leetcode.com/problems/number-of-unique-good-subsequences/discuss/1431819/JavaC++Python-DP-4-lines-O(N)-Time-O(1)-Space
    //
    // note: we dont need to worry about uniqueness property, i.e. double counting!
    // why? at index i, we are adding str[i] to every unique subsequence we have encountered so far.
    // although first char will be the same, the subsequent part will be unique for every subsequence
    //
    // can also generalize to O(1) space based on recurrence
    int numberOfUniqueGoodSubsequences(string binary) {
        bool hasZero = false;
        int modulo = 1e9 + 7;
        int zero = 0;   // number of subsequences ending in a '0'
        int one = 0;    // number of subsequences ending in a '1'
        for (char c : binary) {
            if (c == '0') {
                hasZero = true;
                // if we encounter a zero, we can extend all subsequences we have so far with a zero at the end
                zero = (one + zero) % modulo; 
            } else {
                // if we encounter a one, we can extend all the subsequences we have so far with a one at the end
                // we also need to factor in the case, "1", so +1
                one = (1 + one + zero) % modulo;
            }
        }
        return (zero + one + hasZero) % modulo; 
    }
};
// note: subsequence need not be contiguous!
// "1101" returns 8:
// 1 
// 11
// 110
// 1101
// 0
// 10
// 101
// 111 (non-contiguous)
