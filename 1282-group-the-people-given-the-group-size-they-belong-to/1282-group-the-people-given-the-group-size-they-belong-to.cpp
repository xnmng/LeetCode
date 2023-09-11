class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mp; // groupSize, group
        for (auto i = 0; i < groupSizes.size(); ++i) {
            mp[groupSizes[i]].emplace_back(i);
            if (mp[groupSizes[i]].size() == groupSizes[i]) {
                ans.emplace_back(move(mp[groupSizes[i]]));
                mp[groupSizes[i]] = {};
            }
        }
        return ans;
    }
};