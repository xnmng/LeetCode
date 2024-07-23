class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int i : nums) {
            ++mp[i];
        }
        vector<pair<int,int>> v;
        for (auto i : mp) {
            v.emplace_back(i.second, i.first);
        }
        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        vector<int> ans;
        ans.reserve(nums.size());
        for (auto& [val, k] : v) {
            for (int i = 0; i < val; ++i) {
                ans.emplace_back(k);
            }
        }
        return ans;
    }
};