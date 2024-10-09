class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> selected(n, false);
        vector<int> cur;
        cur.reserve(n);
        vector<vector<int>> ans;
        
        dfs(ans, cur, selected, nums, n);
        
        return ans;
    }
    
    // at each step, take one node then recurse
    void dfs(vector<vector<int>>& ans, vector<int>& cur, 
             vector<bool>& selected, vector<int>& nums, int remaining) {
        if (remaining == 0) {
            ans.emplace_back(cur);
        }
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (!selected[i]) {
                cur.emplace_back(nums[i]);
                selected[i] = true;
                dfs(ans, cur, selected, nums, remaining-1);
                cur.pop_back();
                selected[i] = false;
            }
        }
    }
};