class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int,int> mp;
        for (auto i : nums1) {
            if (mp[i] < 1) mp[i] += 1;
        }
        for (auto i : nums2) {
            if (mp[i] < 2) mp[i] += 2;
        }
        for (auto i : nums3) {
            if (mp[i] < 4) mp[i] += 4;
        }
        vector<int> ans;
        for (auto [k,v] : mp) {
            // cout << k << " " << v << "\n";
            if (v != 1 && v != 2 && v != 4) ans.emplace_back(k);
        }
        return ans;
    }
};