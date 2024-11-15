class Solution {
public:
    // note the constraint! 
    // we can only remove a CONTIGUOUS part of the subarray!

    // https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/solutions/833271/c-with-picture-o-n
    // Algorithm
    // use two pointers pattern to find best split between left and right subarrays:
    // find the longest non-increasing sequence in the right part of the array. 
    // r points to the first element of that sequence.
    // go left-to-right, and for each l increment r while n[r] < n[l].
    // Track the minimum length between left and right in res.
    // Break if n[l] < n[l - 1]. (The left sequence is no longer non-decreasing)
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int right = n-1;
        while (right > 0 && arr[right-1] <= arr[right]) --right;
        int ans = right; // worst case, just remove entire left side
        for (int left = 0; left < right; ++left) {
            if (left > 0 && arr[left-1] > arr[left]) break;
            while (right < n && arr[left] > arr[right]) {
                ++right;
            }
            ans = min(ans, right - left - 1);
        }

        return ans;
    }
};