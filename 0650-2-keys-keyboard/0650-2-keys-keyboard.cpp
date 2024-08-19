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
    
    // bottom up DP 
    // O(n^2) time, O(n) space 
    //
    // consider all possible factors j of i
    // f(i) = f(j) + (i / j) for all j such that i % j == 0
//     int minSteps(int n) {
//         if (n == 1) return 0;
//         vector<int> dp(n+1, 1000);
//         dp[1] = 0;
//         for (int i = 2; i <= n; ++i) {
//             for (int j = 1; j <= i / 2; ++j) {
//                 // Copy All and Paste (i-j) / j times
//                 // for all valid j's
//                 if (i % j == 0) {
//                     dp[i] = min(dp[i], dp[j] + i / j);
//                 }
//             }
//         }

//         return dp[n];
//     }
};