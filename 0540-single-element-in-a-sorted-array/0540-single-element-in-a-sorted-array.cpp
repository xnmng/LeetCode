// mid
class Solution {
private:
    bool isSingleElement(vector<int>& nums, int index) {
        if (index + 1 < nums.size() && nums[index + 1] == nums[index]) return false;
        if (index - 1 >= 0 && nums[index - 1] == nums[index]) return false;
        return true;
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        auto left{0};
        auto right{nums.size() - 1};
        int mid;
        int leftSize;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (isSingleElement(nums, mid)) return nums[mid];
            if (mid == 0) leftSize = 0;
            else leftSize = nums[mid] == nums[mid - 1] ? mid - 1 : mid;
            leftSize % 2 == 0 ? left = mid + 1 : right = mid - 1;
        }
        return -1; // should not happen
    }
};