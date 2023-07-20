class Solution {
private:
    void dfs(vector<int>& nums, vector<int>& cur, vector<bool>& state, vector<vector<int>>& ans) {
        if (cur.size() == nums.size()) {
            ans.emplace_back(cur);
            return;
        }
        for (auto i = 0; i < nums.size(); ++i) {
            if (!state[i]) {
                state[i] = true;
                cur.emplace_back(nums[i]);
                dfs(nums, cur, state, ans);
                cur.pop_back();
                state[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> state(nums.size(), false);
        vector<int> cur;
        dfs(nums, cur, state, ans);
        return ans;
    }
};