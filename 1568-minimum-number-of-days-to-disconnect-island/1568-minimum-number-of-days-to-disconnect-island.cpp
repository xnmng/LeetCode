class Solution {
public:
    // TODO: learn tarjan's algo
    //
    // The most effective way to split an island into two parts 
    //  is to find the thinnest cross-section and change those cells to water. 
    //
    // In a binary grid, even for uniform shapes like squares or circles, 
    // the thinnest cross-section comprises at most 2 squares.
    int minDays(vector<vector<int>>& grid) {
        if (helper(grid)) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (helper(grid)) return 1;
                    grid[i][j] = 1;
                }
                
            }
        }
        
        return 2;
    }
    
    // returns true if island count != 1; false otherwise
    //
    // bfs going to take mn space anyways;
    // might as well make a copy and mutate that
    bool helper(vector<vector<int>> grid) {
        int count = 0;
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++count;
                    q.emplace(i, j);
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        if (visited[x][y]) continue;
                        visited[x][y] = true;
                        grid[x][y] = 0;
                        if (x + 1 < m && grid[x+1][y] == 1 && !visited[x+1][y]) 
                            q.emplace(x+1, y);
                        if (y + 1 < n && grid[x][y+1] == 1 && !visited[x][y+1]) 
                            q.emplace(x, y+1);
                        if (x - 1 >= 0 && grid[x-1][y] == 1 && !visited[x-1][y]) 
                            q.emplace(x-1, y);
                        if (y - 1 >= 0 && grid[x][y-1] == 1 && !visited[x][y-1]) 
                            q.emplace(x, y-1);
                    }
                }
            }
        }

        return count != 1;
    }
};