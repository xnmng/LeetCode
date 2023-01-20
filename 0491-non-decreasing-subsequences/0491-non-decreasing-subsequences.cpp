// https://leetcode.com/problems/non-decreasing-subsequences/discuss/97124/C++-dfs-solution-using-unordered_set
class Solution {
private:
    void dfs(int index, vector<int>& nums, vector<int>& v, vector<vector<int>>& ans) {
        if (v.size() > 1) ans.push_back(v);
        unordered_set<int> s;
        for (auto i = index; i < nums.size(); ++i) {
            if ((v.empty() || nums[i] >= v.back()) 
                && s.find(nums[i]) == s.end()) {
                v.push_back(nums[i]);
                dfs(i+1, nums, v, ans);
                v.pop_back();
                s.insert(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        v.reserve(nums.size());
        vector<vector<int>> ans;
        dfs(0, nums, v, ans);
        return ans;
    }
};