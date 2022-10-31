class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        auto m{matrix.size()};
        auto n{matrix[0].size()};
        auto x{0};
        auto y{0};
        auto val{0};
        for (auto i = 0; i < n; ++i) {
            x = 0;
            y = i;
            val = matrix[x][y];
            while (x < m && y < n) {
                // cout << x << " " << y << "\n";
                if (matrix[x][y] != val) return false;
                ++x;
                ++y;
            }
        }
        for (auto i = 1; i < m; ++i) {
            x = i;
            y = 0;
            val = matrix[x][y];
            while (x < m && y < n) {
                // cout << x << " " << y << "\n";
                if (matrix[x][y] != val) return false;
                ++x;
                ++y;
            }
        }
        return true;
    }
};

// [[18],[66]]
// [[11,74,0,93],[40,11,74,7]]