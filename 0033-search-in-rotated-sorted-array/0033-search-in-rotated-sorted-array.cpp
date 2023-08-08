// https://leetcode.com/problems/search-in-rotated-sorted-array/solution/
class Solution {
public:
    // double binary search (find pivot first then binary search on correct half)
    /*
    idea:
    determine the pivot index (i.e. the index in nums that contains the smallest element)
    apply binary search to either (nums[left] ... nums[pivot]) or (nums[pivot] ... nums[right])
    */
    int search(vector<int>& nums, int target) {
        auto left{0};
        auto right{static_cast<int>(nums.size()-1)};
        while (left < right) {
            auto mid{left + (right - left) / 2};
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int pivot{left};
        // cout << "pivot index is " << pivot << "\n"; 
        if (nums[pivot] <= target && target <= nums.back()) {
            left = pivot;
            right = static_cast<int>(nums.size() - 1);
        } else {
            left = 0;
            right = pivot;
        }
        // cout << left << " " << right << "\n";
        while (left < right) {
            auto mid{left + (right - left) / 2};
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return nums[left] == target ? left : -1;
    }
        
    // single binary search
    /* 
    idea: 
    at each step, either (nums[left] ... nums[mid]) is sorted or (nums[mid] ... nums[right]) is sorted
    determine the sorted half and determine if target is contained inside the sorted half
    repeat to reduce search space
    */
    // int search(vector<int>& nums, int target) {
    //     auto left{0};
    //     auto right{static_cast<int>(nums.size()-1)};
    //     while (left < right) {
    //         auto mid{left + (right - left) / 2};
    //         if (nums[mid] == target) return mid;
    //         // cout << left << " " << mid << " " << right << "\n";            
    //         // either nums[left] ... nums[mid] is sorted or nums[mid] ... nums[right]
    //         if (nums[left] <= nums[mid]) {
    //             // nums[left] ... nums[mid] is sorted
    //             // cout << "index " << left << " to " << mid << " is sorted\n";
    //             // cout << nums[left] << " ... " << nums[mid] << "\n";
    //             if (nums[mid] >= target && target >= nums[left]) {
    //                 right = mid - 1;
    //             } else {
    //                 left = mid + 1;
    //             }
    //         } else {
    //             // nums[mid] ... nums[right] is sorted
    //             // cout << "index " << mid << " to " << right << " is sorted\n";
    //             // cout << nums[mid] << " ... " << nums[right] << "\n";
    //             if (nums[right] >= target && target >= nums[mid]) {
    //                 left = mid + 1;
    //             } else {
    //                 right = mid - 1;
    //             }
    //         }
    //     }
    //     // cout << left << "\n";
    //     return nums[left] == target ? left : -1;
    // }
};
// [3,1]
// 1
// [1,3]
// 3