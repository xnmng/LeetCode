class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int left = 0;
        int right = 0;
        int m = nums1.size();
        int n = nums2.size();
        while (left < m && right < n) {
            if (nums1[left] == nums2[right]) return nums1[left];
            else if (nums1[left] < nums2[right]) ++left;
            else ++right;
        }
        return -1;
    }
};