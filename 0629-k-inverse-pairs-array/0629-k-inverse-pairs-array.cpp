// https://youtu.be/dglwb30bUKI?si=mbegoJShI3CEuTmw
// https://leetcode.com/problems/k-inverse-pairs-array/discuss/846076/C++-4-solutions-with-picture

    // base case (k == 0) implies we dont want any inverse pairs
    // only a sorted array in ascending order (i.e. [1,...,n]) satisfies this condition
    //      when k == 0, return 1
    
    // (brute force idea)
    // suppose at each step, we pick 1 element to be placed at the ith index, 
    // repeating this process with the remaining numbers until we place all n elements
    
    // observation 1:
    // if we pick element i, if i is part of an inverse pair where i is the larger element, 
    // and j is the smaller element
    // we notice that we do not care which index j is at, 
    // since j's index will always be larger than i's index
    //      e.g. suppose we are given [1,2,3,4,5] and we have to pick the first of 5 slots (i.e. X _ _ _ _)
    //      if we pick 3 for the first slot, and since we know all 5 elements have to go in all 5 slots
    //      3 will definitely form an inverse pair with 1 and 2, 
    //      and it does not matter where 1 or 2 go in the remaining slots
    
    // observation 2:
    // we also notice that the numbers dont matter, only the relative ordering
    // if we were given [2,3] vs [1,2], for a given k, they will both yield the same answer
    
    // combining both observations, we notice that once we pick an element, we can compute the number of 
    // inverse pairs it will form where it is the larger element, then treat the remaining elements as [1,...,n]
    // (we have found a subproblem property, hinting at DP)
    
    // top-down DP (v1.0)
    // cache dp(n, k)
    // if k == 0, return 1 
    // if k < 0 (doesnt make semantic sense), return 0
    // for each element, we suppose its the element we pick at this step, 
    //      dp(n, k) += subproblem(n-1, k-inverse_pairs_created)
    // will TLE because time complexity is O(n^2*k), O(n^3) as n,k < 1000
    //      we need to recurse down the recursion tree of height k
    //      we have to slot in n elements, at each step we consider every n element ('fan out' of n^2)
    
    
    // observation 3:
    // if we are at a step with n elements, we can only cause inversions in the range [0,...n-1]
    //      e.g. suppose (n = 4, k), [1,2,3,4]
    //      dp(n,k) = dp(n-1, k) + dp(n-1, k-1) + ... + dp(n-1, k-n+1) (n elements) -- equation 1
    
    // do we really need to consider n elements at each step (i.e. the 'fan out') ?
    // replace equation 1 k with k+1
    //      dp(n,k+1) = dp(n-1, k+1) + dp(n-1, k) + ... + dp(n-1, k-n) (n elements) -- equation 2
    // if we take dp(n,k+1) - dp(n,k),
    //      dp(n,k+1) - dp(n,k) = dp(n-1, k+1) + dp(n-1, k) + ... + dp(n-1, k-n)
    //                                         - dp(n-1, k) - dp(n-1, k-1) - ... - dp(n-1, k-n+1)
    // we obtain
    //      dp(n,k+1) - dp(n,k) = dp(n-1, k+1) - dp(n-1, k-n+1) -- equation 3
    
    // replacing k+1 with k we get
    //      dp(n,k) - dp(n,k-1) = dp(n-1, k) - dp(n-1, k-n)
    //      dp(n,k) = dp(n,k-1) + dp(n-1, k) - dp(n-1, k-n)
    // we can use this equation to reduce each step's 'fan out' from O(n) time to O(1) time,
    // improving our top-down DP solution from O(n^2*k) to O(n*k) time

    // we can also use the recurrence relation to reduce space complexity from O(nk) to O(k) space
class Solution {
public:
    // bottom-up, space optimized
    // also use mod 2 instead of swapping
    // use long to prevent overflow problems (or use int and bottom-up)
    int kInversePairs(int n, int k) {
        vector<vector<long>> dp(2, vector<long>(k+1));

        // init base cases
        for (int i = 0; i < 2; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= k; ++i) {
            dp[0][i] = 0;
        }

        // dont start from base cases (either n or k == 0); already initialized
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                // add modulo amount to prevent underflow issues
                dp[i % 2][j] = ((int)(1e9+7) + dp[(i-1) % 2][j] + dp[i % 2][j-1]
                            - (j-i < 0 ? 0 : dp[(i-1) % 2][j-i]))
                            % (int)(1e9+7);
            }
        }
        return dp[n % 2][k];
    }
    
//     // bottom-up, space optimized
//     // without using the mod 2 trick
//     // use long to prevent overflow problems (or use int and bottom-up)
//     int kInversePairs(int n, int k) {
//         vector<long> dp(k+1, 0);
//         dp[0] = 1;


//         // dont start from base cases (either n or k == 0); already initialized
//         for (int i = 1; i <= n; ++i) {
//             vector<long> next(k+1, 0);
//             next[0] = 1;
//             for (int j = 1; j <= k; ++j) {
//                 // add modulo amount to prevent underflow issues
//                 next[j] = ((int)(1e9+7) + dp[j] + next[j-1]
//                             - (j-i < 0 ? 0 : dp[j-i]))
//                             % (int)(1e9+7);
//             }
//             swap(dp, next);
//         }
//         return dp[k];
//     }
    
    // // bottom-up, non-space optimized
    // // use long to prevent overflow problems (or use int and bottom-up)
    // int kInversePairs(int n, int k) {
    //     vector<vector<long>> dp(n+1, vector<long>(k+1));

    //     // init base cases
    //     for (int i = 0; i <= n; ++i) {
    //         dp[i][0] = 1;
    //     }
    //     for (int i = 1; i <= k; ++i) {
    //         dp[0][i] = 0;
    //     }

    //     // dont start from base cases (either n or k == 0); already initialized
    //     for (int i = 1; i <= n; ++i) {
    //         for (int j = 1; j <= k; ++j) {
    //             // add modulo amount to prevent underflow issues
    //             dp[i][j] = ((int)(1e9+7) + dp[i-1][j] + dp[i][j-1]
    //                         - (j-i < 0 ? 0 : dp[i-1][j-i]))
    //                         % (int)(1e9+7);
    //         }
    //     }
    //     return dp[n][k];
    // }
    
    // // top-down, non-space optimized
    // // use long to prevent overflow problems (or use int and bottom-up)
    // int kInversePairs(int n, int k) {
    //     vector<vector<long>> dp(n+1, vector<long>(k+1, -1));
    //     dfs(n, k, dp);
    //     // for (auto i : dp) {
    //     //     for (auto j : i) cout << j << " ";
    //     //     cout << "\n";
    //     // }
    //     return dp[n][k];
    // }
    // int dfs(int n, int k, vector<vector<long>>& dp) {
    //     if (k < 0 || n < 0) return 0; // semantic error
    //     if (dp[n][k] == -1) {
    //         // handles case k == 0 n == 0 as it will hit first if-block and be set to 1
    //         if (k == 0) {
    //             dp[n][k] = 1;
    //         } else if (n == 0) {
    //             dp[n][k] = 0;                
    //         } else {
    //             // add modulo amount to prevent underflow issues
    //             dp[n][k] = ((long)(1e9+7) + dfs(n, k-1, dp) + dfs(n-1, k, dp) - dfs(n-1, k-n, dp)) % (long)(1e9+7);
    //             // cout << n << " " << k << " depends on " 
    //             //     << n << " " << k-1 << "    " 
    //             //     << n-1 << " " << k << "    "
    //             //     << n-1 << " " << k-n << "\n";
    //             // cout << dfs(n, k-1, dp) << " " << dfs(n-1, k, dp) << " -" << dfs(n-1, k-n, dp) << "\n";
    //             // cout << dp[n][k] << "\n";
    //         }
    //     }
    //     return dp[n][k];
    // }
    
};