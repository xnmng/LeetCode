class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto prev{0};
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[prev] != nums[i]) {
                nums[prev+1] = nums[i];
                ++prev;
            }
        }
        return prev+1;
    }
};