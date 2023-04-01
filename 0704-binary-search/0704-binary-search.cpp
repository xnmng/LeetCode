// https://leetcode.com/problems/binary-search/discuss/423162/Binary-Search-101
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto left{0};
        auto right{static_cast<int>(nums.size() - 1)};
        while (left <= right) {
            auto mid{left + (right - left) / 2};
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
};