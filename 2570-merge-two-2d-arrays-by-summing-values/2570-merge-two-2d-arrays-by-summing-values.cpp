class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int left = 0;
        int right = 0;
        vector<vector<int>> ans;
        int key;
        int val;
        while (left < nums1.size() || right < nums2.size()) {
            key = INT_MAX;
            val = 0;
            if (left < nums1.size()) key = min(key, nums1[left][0]);
            if (right < nums2.size()) key = min(key, nums2[right][0]);

            if (left < nums1.size() && key == nums1[left][0]) {
                val += nums1[left][1];
                ++left;
            }

            if (right < nums2.size() && key == nums2[right][0]) {
                val += nums2[right][1];
                ++right;
            }

            ans.push_back({key, val});
        }
        return ans;
    }
};