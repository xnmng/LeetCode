class Solution {
public:
    // constraints small; brute force
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>> extra;
        vector<pair<int,int>> missing;
        extra.reserve(9);
        missing.reserve(9);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 0) missing.emplace_back(i, j);
                else if (grid[i][j] > 1) extra.emplace_back(i, j);
            }
        }
        return dfs(grid, extra, missing);
    }
    
    // match each missing square with one of the extra grids
    // try all possible combinations
    int dfs(vector<vector<int>>& grid, 
            vector<pair<int,int>>& extra, 
            vector<pair<int,int>>& missing,
           int index = 0) {
        if (missing.size() == index) return 0;
        auto [i,j] = missing[index];
        int cost = INT_MAX;
        for (auto& [x,y] : extra) {
            if (grid[x][y] == 1) continue;
            --grid[x][y];
            int temp = abs(x - i) + abs(y - j) + dfs(grid, extra, missing, index + 1);
            ++grid[x][y];
            cost = min(cost, temp);
        }
        return cost;
    }
};