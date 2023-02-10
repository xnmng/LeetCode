class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        auto n{grid.size()};
        vector<pair<int,int>> v;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (grid[i][j] == 1) v.emplace_back(i, j);
            }
        }
        if (v.empty()) return -1;
        int ans{-1};
        int d;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    d = INT_MAX;
                    for (auto& [x, y] : v) {
                        d = min(d, abs(x - i) + abs(y - j));
                    }
                    // cout << d << "\n";
                    ans = max(ans, d);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
// [[1,0,1],[0,0,0],[1,0,1]]