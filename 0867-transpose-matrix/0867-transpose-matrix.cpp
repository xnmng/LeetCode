class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        auto m{matrix.size()};
        auto n{matrix[0].size()};
        vector<vector<int>> ans(n, vector<int>(m));
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};