// https://leetcode.com/problems/number-of-1-bits/discuss/1044799/C++-or-Bit-Manipulation-or-4-Approaches-or-Beats-100-0ms-O(1)
// https://leetcode.com/problems/number-of-1-bits/discuss/55255/C++-Solution:-n-and-(n-1)
// https://graphics.stanford.edu/~seander/bithacks.html
class Solution {
public:
    // n & (n-1) drops a '1' bit from the number
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n != 0) {
            n = n & (n-1);
            ++ans;
        }
        return ans;
    }
    
    // int hammingWeight(uint32_t n) {
    //     int ans = 0;
    //     while (n != 0) {
    //         ans += n % 2;
    //         n /= 2;
    //     }
    //     return ans;
    // }
};