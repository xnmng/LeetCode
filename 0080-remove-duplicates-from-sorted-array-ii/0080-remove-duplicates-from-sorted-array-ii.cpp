class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int next = 2;
        for (auto i = 2; i < nums.size(); ++i) {
            // dont need to check nums[next-1] as if nums[i] == nums[next-2],
            // it also implies nums[i] == nums[next-1]
            if (nums[i] != nums[next-2]) {
                swap(nums[next], nums[i]);
                ++next;
            }
        }
        return min(static_cast<int>(nums.size()), next);
    }
};
// [1]