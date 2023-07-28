class Solution {
private:
    int dfs(vector<int>& nums, vector<vector<int>>& dp, int begin, int end) {
        if (dp[begin][end] == INT_MIN) {
            if (end - begin == 1) {
                dp[begin][end] = nums[begin];
            } else {
                dp[begin][end] = max(nums[begin] - dfs(nums, dp, begin+1, end),
                                    nums[end-1] - dfs(nums, dp, begin, end-1));
            }
        }
        return dp[begin][end];
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, INT_MIN));
        dfs(nums, dp, 0, nums.size());
        // for (auto i : dp) {
        //     for (auto j : i) cout << j << " ";
        //     cout << "\n";
        // }
        return dp[0][nums.size()] >= 0;
    }
};