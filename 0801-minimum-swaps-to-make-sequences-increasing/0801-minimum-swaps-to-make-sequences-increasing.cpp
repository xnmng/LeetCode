class Solution {
public:
    // the recurrence is only based on previous element, can do O(1) space DP
    // swap[i] := min cost to make sequence up to i increasing, and we swapped ith pair
    // noSwap[i] := min cost to make sequence up to i increasing, and we didnt swap ith pair
    // O(n) time, O(1) space DP
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int prevSwap = 1;
        int prevNoSwap = 0;
        int swap;
        int noSwap;
        int n = nums1.size();
        for (int i = 1; i < n; ++i) {
            // this index matches with other prev index
            // either dont swap or swap both
            if (nums1[i] > nums1[i-1] && 
                nums2[i] > nums2[i-1]) {
                swap = prevSwap + 1;
                noSwap = prevNoSwap;
            }
            // this index does not match with prev index
            // if we didnt swap prev, we should swap this
            // if we swap this, we should not swap prev
            if (nums1[i] > nums2[i-1] && 
                nums2[i] > nums1[i-1]) {
                swap = min(swap, prevNoSwap + 1);
                noSwap = min(noSwap, prevSwap);
            }
            // update state, reset next index
            prevSwap = swap;
            prevNoSwap = noSwap;
            swap = n;
            noSwap = n;
        }
        return min(prevSwap, prevNoSwap);
    }
};