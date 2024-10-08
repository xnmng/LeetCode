// count using dfs
class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
        // cout << i << " " << j << "\n";
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            dfs(grid, i+1, j);
            dfs(grid, i, j+1);
            dfs(grid, i-1, j);
            dfs(grid, i, j-1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        auto ans{0};
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++ans;
                    dfs(grid, i, j);
                }
            } 
        }
        return ans;
    }
};

// [["1"],["1"]]
// [["1","1","1"],["0","1","0"],["1","1","1"]]