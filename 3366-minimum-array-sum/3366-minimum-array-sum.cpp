class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        // index, op1 remaining, op2 remaining
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        return dfs(nums, k, dp, 0, op1, op2);
    }

    int dfs(vector<int>& nums, int k, vector<vector<vector<int>>>& dp, int i, int op1, int op2) {
        int n = nums.size();
        if (i == n) return 0;
        if (dp[i][op1][op2] == -1) {
            int cur = nums[i];
            int ideal = cur + dfs(nums, k, dp, i+1, op1, op2);
            if (op1 > 0) {
                ideal = min(ideal,
                            ((cur + 1) / 2) + dfs(nums, k, dp, i+1, op1-1, op2));
            }
            if (op2 > 0 && cur >= k) {
                ideal = min(ideal,
                            (cur - k) + dfs(nums, k, dp, i+1, op1, op2-1));
            }
            if (op1 > 0 && op2 > 0) {
                int n1 = (cur + 1) / 2;
                if (n1 >= k) n1 -= k;
                ideal = min(ideal,
                            n1 + dfs(nums, k, dp, i+1, op1-1, op2-1));
                if (cur >= k) {
                    n1 = (cur - k + 1) / 2;
                    ideal = min(ideal,
                                n1 + dfs(nums, k, dp, i+1, op1-1, op2-1));
                }
            }
            dp[i][op1][op2] = ideal;
        } 
        return dp[i][op1][op2];
    }
};