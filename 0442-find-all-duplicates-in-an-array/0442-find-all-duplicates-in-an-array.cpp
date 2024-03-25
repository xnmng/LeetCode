class Solution {
public:
    // each integer only appears once or twice; use input arr as space
    // set flag to -1, if encountered again, this number is a duplicate
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int val;
        for (auto i = 0; i < nums.size(); ++i) {
            val = abs(nums[i]);
            if (nums[val-1] < 0) ans.emplace_back(val);
            else nums[val-1] *= -1;
        }
        return ans;
    }
};