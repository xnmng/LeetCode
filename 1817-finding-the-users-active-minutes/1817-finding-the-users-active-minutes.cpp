class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k, 0);
        unordered_map<int, unordered_set<int>> mp;
        for (auto& i : logs) {
            mp[i[0]].insert(i[1]);
        }
        for (auto& [id,set] : mp) {
            ++ans[set.size()-1]; // answer needs to be 1-indexed
        }
        return ans;
    }
};