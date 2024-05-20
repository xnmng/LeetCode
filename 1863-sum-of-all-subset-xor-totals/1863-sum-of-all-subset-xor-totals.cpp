class Solution {
public:
    int subsetXORSum(vector<int>& nums, int index = 0, int cur = 0) {
        if (index == nums.size()) return cur;
        return subsetXORSum(nums, index + 1, cur) 
                + subsetXORSum(nums, index + 1, cur ^ nums[index]);
    }
};