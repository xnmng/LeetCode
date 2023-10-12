/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    // copied from 162. Find Peak Element (https://leetcode.com/submissions/detail/1073105428/)
    int helper(MountainArray &mountainArr, int n) {
        
        if (n == 1) return 0;
        if (mountainArr.get(0) > mountainArr.get(1)) return 0;
        if (mountainArr.get(n-2) < mountainArr.get(n-1)) return n-1;
        
        // we ruled out the case where start/end of arr is peak
        // search on remaining elements
        int left = 1;
        int right = n-2;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mountainArr.get(mid-1) < mountainArr.get(mid) 
                && mountainArr.get(mid) > mountainArr.get(mid+1)) break;
            else if (mountainArr.get(mid-1) > mountainArr.get(mid)) right = mid-1;
            else if (mountainArr.get(mid) < mountainArr.get(mid+1)) left = mid+1;
        }
        return mid;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peakIndex = helper(mountainArr, n);
        
        // cout << "peakIndex=" << peakIndex << "\n";
        if (mountainArr.get(peakIndex) == target) return peakIndex;
        // if peak isnt target, binary search on left and right to find peak
        int left = 0;
        int right = peakIndex-1;
        int mid = 0;
        int val = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            val = mountainArr.get(mid);
            if (val == target) break;
            if (val > target) { // arr[mid] >= target
                right = mid-1;
            }
            else { // val/arr[mid] < target
                left = mid+1;
            }
            // cout << left << " " << mid << " " << right << "\n";
        }
        // cout << "mid=" << mid << ", arr[mid]=" << mountainArr.get(mid) << "\n";
        if (mountainArr.get(mid) == target) return mid;
        
        left = peakIndex+1;
        right = n-1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            val = mountainArr.get(mid);
            if (val == target) break;
            if (val > target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
            // cout << left << " " << mid << " " << right << "\n";
        }
        // cout << "mid=" << mid << ", arr[mid]=" << mountainArr.get(mid) << "\n";
        
        if (mountainArr.get(mid) == target) return mid;
        return -1;
    }
};

// [1,2,3,4,5,3,1]
// 2
// [1,5,2]
// 0
// [1,2,5,1]
// 2
// [1,2,5,1]
// 0
// [1,5,2]
// 2
// [0,5,3,1]
// 1