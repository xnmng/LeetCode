// https://leetcode.com/problems/maximum-length-of-pair-chain/solution/
class Solution {
public:
    // greedy solution: O(nlogn) time, O(1) space
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), 
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });
        int ans{0};
        int prev{INT_MIN};
        for (auto& pair : pairs) {
            if (pair[0] > prev) {
                ++ans;
                prev = pair[1];
            }
        }
        return ans;
    }
    
    // dp solution: O(n^2) time, O(n) space
    // int findLongestChain(vector<vector<int>>& pairs) {
    //     sort(pairs.begin(), pairs.end());
    //     size_t n{pairs.size()};
    //     vector<int> dp(n, 1);
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j < i; ++j) {
    //             if (pairs[j][1] < pairs[i][0]) dp[i] = max(dp[i], 1 + dp[j]);
    //         }
    //     }
    //     return dp.back();
    // }
};