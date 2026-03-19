class Solution {
public:
    // initially, let 'x' = 1, 'y' = -1, '.' = 0
    // then, submatrix should contain prefix sum of 0
    // to avoid counting submatrices with only '.', set x to 10001
    // that way, we can check if sum is (> 0) and (% 10000 == 0) instead
    // (10000 because the grid is max 1000 by 1000, 
    // avoid edge case where we have all x's and modulo wraps around)
    // 
    // use long to prevent overflow
    // O(mn) time, O(mn) space
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long>> v(m, vector<long>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'X') v[i][j] = 10001;
                else if (grid[i][j] == 'Y') v[i][j] = -1;

                if (i > 0) v[i][j] += v[i-1][j];
                if (j > 0) v[i][j] += v[i][j-1];
                if (i > 0 && j > 0) v[i][j] -= v[i-1][j-1];
                if (v[i][j] > 0 && v[i][j] % 10000 == 0) ++ans;
                // cout << v[i][j] << " ";
            }
            // cout << "\n";
        }
        return ans;
    }
};