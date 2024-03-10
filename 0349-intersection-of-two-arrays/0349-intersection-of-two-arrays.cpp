class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        ans.reserve(min(nums1.size(), nums2.size()));
        unordered_map<int,int> mp;
        for (int i : nums1) ++mp[i];
        for (int i : nums2) {
            if (mp.find(i) != mp.end()) {
                ans.emplace_back(i);
                mp.erase(i);
            }
        }
        return ans;
    }
};