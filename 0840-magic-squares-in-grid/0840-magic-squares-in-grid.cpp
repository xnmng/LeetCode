class Solution {
    bool isMagicSquare(vector<vector<int>>& grid, int i, int j) {
        unordered_set<int> s;
        for (auto x = i-2; x <= i; ++x) {
            for (auto y = j-2; y <= j; ++y) {
                s.insert(grid[x][y]);
            }
        }
        for (auto k = 1; k <= 9; ++k) {
            if (s.find(k) == s.end()) return false;
        }
        
        return 15 == grid[i][j] + grid[i-1][j-1] + grid[i-2][j-2]
            && 15 == grid[i][j-2] + grid[i-1][j-1] + grid[i-2][j]

            && 15 == grid[i][j] + grid[i-1][j] + grid[i-2][j]
            && 15 == grid[i][j-1] + grid[i-1][j-1] + grid[i-2][j-1]
            && 15 == grid[i][j-2] + grid[i-1][j-2] + grid[i-2][j-2]
            
            && 15 == grid[i][j] + grid[i][j-1] + grid[i][j-2]
            && 15 == grid[i-1][j] + grid[i-1][j-1] + grid[i-1][j-2]
            && 15 == grid[i-2][j] + grid[i-2][j-1] + grid[i-2][j-2];
        }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3) return 0;
        auto m{grid.size()};
        auto n{grid[0].size()};
        auto ans{0};
        for (auto i = 2; i < m; ++i) {
            for (auto j = 2; j < n; ++j) {
                if (isMagicSquare(grid, i, j)) ++ans;
            }
        }
        return ans;
    }
};