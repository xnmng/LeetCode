class Solution {
public:
    // TODO: solve using union find disjoint set
    //
    // follow the definition stated in the question:
    //
    // An island in grid2 is considered a sub-island if there is an island in grid1 that 
    // contains all the cells that make up this island in grid2.
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    if (bfs(i, j, grid1, grid2, visited)) {
                        // cout << i << " " << j << "\n";
                        ++ans;
                    }
                }    
            }
        }
        return ans;
    }
    
    bool bfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited) {
        int m = grid1.size();
        int n = grid1[0].size();
        queue<pair<int,int>> q;
        q.emplace(i, j);
        int res = true;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (visited[x][y]) continue;
            visited[x][y] = true;
            if (grid2[x][y] == 1 && grid1[x][y] == 0) {
                res = false;
                // cout << "marked false\n";
            }
            grid2[x][y] = 0;
            if (x + 1 < m && grid2[x+1][y] == 1 && !visited[x+1][y]) q.emplace(x+1, y);
            if (y + 1 < n && grid2[x][y+1] == 1 && !visited[x][y+1]) q.emplace(x, y+1);
            if (x - 1 >= 0 && grid2[x-1][y] == 1 && !visited[x-1][y]) q.emplace(x-1, y);
            if (y - 1 >= 0 && grid2[x][y-1] == 1 && !visited[x][y-1]) q.emplace(x, y-1);
        }
        return res;
    }
};