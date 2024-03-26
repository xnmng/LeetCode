class Solution {
public:
    // since we only have n numbers, the answer definitely lies in the range [1,n]
    //
    // to handle the edge case of nums[i] == 0, increment first, then during checking, return i+1
    int firstMissingPositive(vector<int>& nums) {
        for (auto& i : nums) {
            if (i <= 0) i = nums.size()+1;
        }
        int cur;
        for (auto& i : nums) {
            cur = abs(i);
            if (cur > nums.size()) continue;
            if (nums[cur-1] > 0) nums[cur-1] *= -1;
        }
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) return i+1;
        }
        return nums.size()+1;
    }
};