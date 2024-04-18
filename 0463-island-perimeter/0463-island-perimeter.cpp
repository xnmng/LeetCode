class Solution {
public:
    // O(n) space if cannot modify input
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, m, n, ans, visited);
                    break;
                }
            }
            if (ans > 0) break;
        }
        return ans;
    }
    
    // check for adj squares, -1 for each, dfs only if yet to visit that square
    void dfs(vector<vector<int>>& grid, 
             int i, int j, int m, int n, int& ans, 
             vector<vector<bool>>& visited) {
        // cout << i << " " << j << "\n";
        ans += 4;
        visited[i][j] = true;
        if (i+1 < m && grid[i+1][j] == 1) {
            ans -= 1;
            if (!visited[i+1][j]) dfs(grid, i+1, j, m, n, ans, visited);
        }
        if (j+1 < n && grid[i][j+1] == 1) {
            ans -= 1;
            if (!visited[i][j+1]) dfs(grid, i, j+1, m, n, ans, visited);
        }
        if (i-1 >= 0 && grid[i-1][j] == 1) {
            ans -= 1;
            if (!visited[i-1][j]) dfs(grid, i-1, j, m, n, ans, visited);
        }
        if (j-1 >= 0 && grid[i][j-1] == 1) {
            ans -= 1;
            if (!visited[i][j-1]) dfs(grid, i, j-1, m, n, ans, visited);
        }
    }
};
// [[1,1],[1,1]]