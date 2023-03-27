class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (i >= 1 && j >= 1) {
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }
                else if (i >= 1) grid[i][j] += grid[i-1][j];
                else if (j >= 1) grid[i][j] += grid[i][j-1];
            }
        }
        // for (auto i : grid) {
        //     for (auto j : i) {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        return grid.back().back();
    }
};