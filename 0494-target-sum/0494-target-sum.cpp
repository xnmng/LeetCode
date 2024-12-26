class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        dfs(nums, target, ans);
        return ans;
    }

    void dfs(vector<int>& nums, int target, int& ans, int index = 0, int sum = 0) {
        if (index == nums.size()) {
            if (sum == target) ++ans;
            return;
        }
        dfs(nums, target, ans, index + 1, sum + nums[index]);
        dfs(nums, target, ans, index + 1, sum - nums[index]);
    }
};