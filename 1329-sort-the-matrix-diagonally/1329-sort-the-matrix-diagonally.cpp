class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> cur;
        for (auto i = 0; i < mat[0].size(); ++i) {
            cur.clear();
            for (auto j = 0; i + j < mat[0].size() && j < mat.size(); ++j) {
                cur.push_back(mat[j][i+j]);
                // cout << j << " " << i+j << "\n";
            }
            // cout << "\n";
            sort(cur.begin(), cur.end());
            for (auto j = 0; i + j < mat[0].size() && j < mat.size(); ++j) {
                mat[j][i+j] = cur[j];
            }
        }
        for (auto i = 1; i < mat.size(); ++i) {
            cur.clear();
            for (auto j = 0; i + j < mat.size() && j < mat[0].size(); ++j) {
                cur.push_back(mat[i+j][j]);
                // cout << i+j << " " << j << "\n";
            }
            // cout << "\n";
            sort(cur.begin(), cur.end());
            for (auto j = 0; i + j < mat.size() && j < mat[0].size(); ++j) {
                mat[i+j][j] = cur[j];
            }
        }
        return mat;
    }
};