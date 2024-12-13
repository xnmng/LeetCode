class Solution {
public:
    // dp[bitmask][last_index_used]
    // top down dp, base case when all numbers are used = 1
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long>> dp((1 << n), vector<long>(n, -1));
        return dfs(nums, dp, 0, -1);
    }

    int dfs(vector<int>& nums, vector<vector<long>>& dp, int mask, int last_used) {
        int n = nums.size();
        int modulo = 1e9 + 7;

        if (mask == ((1 << n) - 1)) return 1;
        if (last_used != -1 && dp[mask][last_used] != -1) 
            return dp[mask][last_used];

        long res = 0;
        for (int i = 0; i < n; ++i) {
            if (((1 << i) & mask) == 0 && 
                (last_used == -1 || 
                 nums[last_used] % nums[i] == 0 || 
                 nums[i] % nums[last_used] == 0)) {
                res = (res + dfs(nums, dp, mask | (1 << i), i)) % modulo;
            }
        }

        if (last_used != -1) dp[mask][last_used] = res;
        return res;
    }
};
