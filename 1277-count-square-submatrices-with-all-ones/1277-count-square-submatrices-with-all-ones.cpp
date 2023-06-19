class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        auto ans{0};
        auto m{matrix.size()};
        auto n{matrix[0].size()};
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (i > 0 && j > 0) {
                    if (matrix[i][j] == 1) {
                        matrix[i][j] += min(
                            min(matrix[i-1][j], matrix[i][j-1]), 
                            matrix[i-1][j-1]);
                        ans += matrix[i][j];
                    }
                } else if (matrix[i][j] == 1) ++ans;
            }
        }
        return ans;
    }
};