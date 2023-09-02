class Solution {
private:
    // transpose then reflect about any axis
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < i; ++j) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (auto i = 0; i < (n+1) / 2; ++i) {
            for (auto j = 0; j < n; ++j) {
                swap(mat[j][i], mat[j][n-1-i]);
            }
        }
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target, int count = 0) {
        if (count == 4) return false;
        if (mat == target) return true;
        rotate(mat);
        return findRotation(mat, target, count+1);
    }
};