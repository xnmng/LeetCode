class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) continue;
                if (dfs(grid, visited, i, j)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& grid, 
             vector<vector<bool>>& visited,
             int i, int j, 
             int previ = -1, int prevj = -1, int steps = 0) {
        if (visited[i][j] && steps >= 4) return true;
        visited[i][j] = true;
        int m = grid.size();
        int n = grid[0].size();
        bool ans = false;
        // only need to check updated step (i.e. i/j)
        if (i+1 < m && grid[i][j] == grid[i+1][j] && i+1 != previ) {
            ans |= dfs(grid, visited, i+1, j, i, j, steps+1);
        }
        if (j+1 < n && grid[i][j] == grid[i][j+1] && j+1 != prevj) {
            ans |= dfs(grid, visited, i, j+1, i, j, steps+1);
        }
        if (i-1 >= 0 && grid[i][j] == grid[i-1][j] && i-1 != previ) {
            ans |= dfs(grid, visited, i-1, j, i, j, steps+1);
        }
        if (j-1 >= 0 && grid[i][j] == grid[i][j-1] && j-1 != prevj) {
            ans |= dfs(grid, visited, i, j-1, i, j, steps+1);
        }
        return ans;
    }
};