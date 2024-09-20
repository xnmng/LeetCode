class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int left = INT_MAX;
        int right = INT_MIN;
        int up = INT_MAX;
        int down = INT_MIN;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    left = min(left, j);
                    right = max(right, j);
                    up = min(up, i);
                    down = max(down, i);
                }
            }
        }
        // cout << left << " " << right << " " << up << " " << down << "\n";
        return (down - up + 1) * (right - left + 1);
    }
};