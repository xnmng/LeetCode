class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int,vector<int>> mp;
        unordered_set<int> win;
        for (auto i : pick) {
            if (mp.find(i[0]) == mp.end()) {
                mp.emplace(i[0], vector<int>(11, 0));
            }
            ++mp[i[0]][i[1]];
            if (mp[i[0]][i[1]] == (i[0] + 1)) win.insert(i[0]);
        }
        return win.size();
    }
};