class Solution {
public:
    // https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/discuss/5389350/JavaC++Python-1d-DP
    //
    // if we take mod k, the number of sequences we have are 0, 1, ..., k
    // check each possible subsequence then return O(n * k) time, 10^3 * 10^3 ~ 10^6 (OK)
    //
    // 
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        // go through each possible modulo
        for (int i = 0; i < k; ++i) {
            vector<int> dp(k, 0);
            for (int j : nums) {
                dp[j % k] = 1 + dp[(i - (j % k) + k) % k]; 
                ans = max(ans, dp[j % k]);
            }
        }
        return ans;
    }
};