// https://leetcode.com/problems/search-in-rotated-sorted-array/solution/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto left{0};
        auto right{static_cast<int>(nums.size()-1)};
        while (left < right) {
            auto mid{left + (right - left) / 2};
            if (nums[mid] == target) return mid;
            // cout << left << " " << mid << " " << right << "\n";            
            // either nums[left] ... nums[mid] is sorted or nums[mid] ... nums[right]
            if (nums[left] <= nums[mid]) {
                // nums[left] ... nums[mid] is sorted
                // cout << "index " << left << " to " << mid << " is sorted\n";
                // cout << nums[left] << " ... " << nums[mid] << "\n";
                if (nums[mid] >= target && target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // nums[mid] ... nums[right] is sorted
                // cout << "index " << mid << " to " << right << " is sorted\n";
                // cout << nums[mid] << " ... " << nums[right] << "\n";
                if (nums[right] >= target && target >= nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        // cout << left << "\n";
        return nums[left] == target ? left : -1;
    }
};
// [3,1]
// 1