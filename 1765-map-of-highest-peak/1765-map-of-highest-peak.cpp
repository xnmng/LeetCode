// https://leetcode.com/problems/map-of-highest-peak/discuss/1076933/C++-with-picture-(of-Mars)
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        auto m{static_cast<int>(isWater.size())};
        auto n{static_cast<int>(isWater[0].size())};
        queue<pair<int,int>> q;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    q.emplace(i, j);
                    ans[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto x{q.front().first};
            auto y{q.front().second};
            auto val{ans[x][y]};
            q.pop();
            if (x+1 < m && ans[x+1][y] < 0) {
                ans[x+1][y] = 1 + val;
                q.emplace(x+1, y);      
            }
            if (x-1 >= 0 && ans[x-1][y] < 0) {
                ans[x-1][y] = 1 + val;
                q.emplace(x-1, y);
            }
            if (y+1 < n && ans[x][y+1] < 0) {
                ans[x][y+1] = 1 + val;
                q.emplace(x, y+1);
            }
            if (y-1 >= 0 && ans[x][y-1] < 0) {
                ans[x][y-1] = 1 + val;
                q.emplace(x, y-1);
            }
        }
        return ans;
    }
};