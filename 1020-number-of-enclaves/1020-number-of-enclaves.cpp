class Solution {
private:
    void dfs(vector<vector<int>>& grid, int x, int y, int& count) {
        ++count;
        grid[x][y] = 0;
        auto m{grid.size()};
        auto n{grid[0].size()};
        if (x+1 < m && grid[x+1][y] == 1) dfs(grid, x+1, y, count);        
        if (y+1 < n && grid[x][y+1] == 1) dfs(grid, x, y+1, count);      
        if (x-1 >= 0 && grid[x-1][y] == 1) dfs(grid, x-1, y, count);        
        if (y-1 >= 0 && grid[x][y-1] == 1) dfs(grid, x, y-1, count);    
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        auto m{grid.size()};
        auto n{grid[0].size()};
        auto ans{0};
        for (auto i = 0; i < m; ++i) {
            if (grid[i][0] == 1) {
                dfs(grid, i, 0, ans);
            }
            if (grid[i][n-1] == 1) {
                dfs(grid, i, n-1, ans);
            }
        }
        for (auto i = 0; i < n; ++i) {
            if (grid[0][i] == 1) {
                dfs(grid, 0, i, ans);
            }
            if (grid[m-1][i] == 1) {
                dfs(grid, m-1, i, ans);
            }
        }
        ans = 0;
        for (auto i = 1; i < m-1; ++i) {
            for (auto j = 1; j < n-1; ++j) {
                if (grid[i][j] == 1) dfs(grid, i, j, ans);
            }
        }
        return ans;
    }
};