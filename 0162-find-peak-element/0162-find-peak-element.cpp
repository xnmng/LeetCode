// https://leetcode.com/problems/find-peak-element/discuss/1290642/Intuition-behind-conditions-or-Complete-Explanation-or-Diagram-or-Binary-Search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-2] < nums[n-1]) return n-1;
        
        // we ruled out the case where start/end of arr is peak
        // search on remaining elements
        int left = 1;
        int right = n-2;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) break;
            else if (nums[mid-1] > nums[mid]) right = mid-1;
            else if (nums[mid] < nums[mid+1]) left = mid+1;
        }
        return mid;
    }
};