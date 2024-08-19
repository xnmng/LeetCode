class Solution {
public:
    // https://leetcode.com/problems/2-keys-keyboard/solution/
    // the optimal strategy involves breaking down each composite [CP...P] into its prime factors
    // O(n) time, O(1) space
    int minSteps(int n) {
        if (n == 1) return 0;
        int ans = 0;
        int d = 2;
        while (n > 1) {
            // If d is prime factor, keep dividing
            // n by d until is no longer divisible
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            ++d;
        }
        return ans;
    }
};