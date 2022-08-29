class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& v) {
        if (i >= grid.size() || j >= grid[0].size() || v[i][j] == 1) return;
        // cout << i << " " << j << "\n";
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            dfs(grid, i+1, j, v);
            dfs(grid, i, j+1, v);
            dfs(grid, i-1, j, v);
            dfs(grid, i, j-1, v);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        auto ans{0};
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++ans;
                    vector<vector<int>> v(grid.size(), vector<int>(grid[0].size(), 0));
                    dfs(grid, i, j, v);
                }
            } 
        }
        return ans;
    }
};

// [["1"],["1"]]
// [["1","1","1"],["0","1","0"],["1","1","1"]]