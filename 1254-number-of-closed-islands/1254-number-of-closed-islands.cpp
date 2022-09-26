// https://leetcode.com/problems/number-of-closed-islands/discuss/425150/JavaC++-with-picture-Number-of-Enclaves
// flood fill from border, then perform dfs on indexes with 0
class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 1;
        if (i+1 < grid.size() && grid[i+1][j] == 0) dfs(grid, i+1, j);
        if (i-1 >= 0 && grid[i-1][j] == 0) dfs(grid, i-1, j);
        if (j+1 < grid[0].size() && grid[i][j+1] == 0) dfs(grid, i, j+1);
        if (j-1 >= 0 && grid[i][j-1] == 0) dfs(grid, i, j-1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m{static_cast<int>(grid.size())};
        int n{static_cast<int>(grid[0].size())};
        for (auto i = 0; i < m; ++i) {
            if (grid[i][0] == 0) dfs(grid, i, 0);
            if (grid[i][n-1] == 0) dfs(grid, i, n-1);
        }
        for (auto i = 0; i < n; ++i) {
            if (grid[0][i] == 0) dfs(grid, 0, i);
            if (grid[m-1][i] == 0) dfs(grid, m-1, i);
        }
        
        auto ans{0};
        for (auto i = 1; i < m; ++i) {
            for (auto j = 1; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};