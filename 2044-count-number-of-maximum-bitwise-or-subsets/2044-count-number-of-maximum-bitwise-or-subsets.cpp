class Solution {
private:
    void dfs(vector<int>& nums, int index, int cur, int maximum, int& ans) {
        // cout << index << "\n";
        if (index == nums.size()) return;
        if ((cur | nums[index]) == maximum) ++ans;
        dfs(nums, index + 1, cur | nums[index], maximum, ans);
        dfs(nums, index + 1, cur, maximum, ans);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        auto maximum{0};
        for (auto i : nums) maximum |= i;
        // cout << "max: " << maximum << "\n";
        auto ans{0};
        dfs(nums, 0, 0, maximum, ans);
        return ans;
    }
};