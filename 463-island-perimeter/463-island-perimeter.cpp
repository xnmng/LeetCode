class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        auto ans{0};
        auto m{grid.size()};
        auto n{grid[0].size()};
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (i-1 < 0 || grid[i-1][j] == 0) ++ans;
                    if (i+1 == m || grid[i+1][j] == 0) ++ans;
                    if (j-1 < 0 || grid[i][j-1] == 0) ++ans;
                    if (j+1 == n || grid[i][j+1] == 0) ++ans;
                }
            }
        }
        return ans;
    }
};