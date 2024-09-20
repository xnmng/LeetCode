class Solution {
public:
    // since we need 1 rectangle to cover all the 1's and we want minimum area,
    // just make the rectangle just big enough to cover all the 1's
    // to do this, we just maintain the bounds of each 1, 
    // take the max bound (up, down, left, right) of each
    // and find the area of this rectangle drawn by these 4 bounds
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
        return (down - up + 1) * (right - left + 1);
    }
};