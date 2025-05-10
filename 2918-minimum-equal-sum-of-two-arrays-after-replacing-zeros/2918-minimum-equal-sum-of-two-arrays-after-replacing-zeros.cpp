class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int count1 = 0;
        int count2 = 0;
        long long nums1_total = 0;
        long long nums2_total = 0;
        for (int i : nums1) {
            nums1_total += i;
            if (i == 0) ++count1;
        }
        for (int i : nums2) {
            nums2_total += i;
            if (i == 0) ++count2;
        }

        if (count1 == 0 && count2 == 0 && nums1_total != nums2_total) return -1;

        // edge cases (if A has no 0's and B's sum + B's 0's > A's sum)
        if (count1 > 0 && count2 == 0 && (nums1_total + count1) > nums2_total) return -1;
        if (count2 > 0 && count1 == 0 && (nums2_total + count2) > nums1_total) return -1;

        // greedy
        return max(nums1_total + count1, nums2_total + count2);
    }
};