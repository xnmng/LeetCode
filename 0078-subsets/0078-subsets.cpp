class Solution {
    void dfs(vector<int>& nums, vector<int>& cur, int index, vector<vector<int>>& ans) {
        if (index == nums.size()) return;
        cur.push_back(nums[index]);
        ans.push_back(cur);
        dfs(nums, cur, index+1, ans);
        cur.pop_back();
        dfs(nums, cur, index+1, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans{{}};
        dfs(nums, cur, 0, ans);
        return ans;
    }
};