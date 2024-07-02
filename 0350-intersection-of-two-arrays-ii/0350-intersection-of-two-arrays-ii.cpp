class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        ans.reserve(nums1.size());
        unordered_map<int,int> mp;
        for (int i : nums1) {
            ++mp[i];
        }
        for (int i : nums2) {
            if (mp[i] > 0) {
                ans.emplace_back(i);
                --mp[i];
            }
        }
        return ans;
    }
};