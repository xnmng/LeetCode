class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto left{0};
        auto right{static_cast<int>(nums.size() - 1)};
        int mid;
        while (left <= right) {
            mid = left + ((right - left) / 2);
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) {
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
            // cout << left << " " << right << "\n";
        }
        return left;
    }
};

// [1,3,5,6]
// 0