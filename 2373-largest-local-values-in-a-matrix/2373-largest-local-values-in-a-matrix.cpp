class Solution {
public:
    // brute force, nothing challenging, only testing if you know how to code
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        for (int i = 1; i < n-1; ++i) {
            for (int j = 1; j < n-1; ++j) {
                // cout << i << " " << j << "\n";
                // cout << i-1 << " " << j-1 << "\n";
                for (int x = -1; x <= 1; ++x) {
                    for (int y = -1; y <= 1; ++y) {
                        ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i + x][j + y]);
                    }
                }
            }
        }
        return ans;
    }
};