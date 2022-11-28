class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2, vector<int>());
        map<int,int> mp;
        for (auto& i : matches) {
            mp[i[0]];
            mp[i[1]]++;
        }
        for (auto& [i, j] : mp) {
            if (j == 0) ans[0].push_back(i);
            else if (j == 1) ans[1].push_back(i);
        }
        return ans;
    }
};