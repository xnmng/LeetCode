// https://youtu.be/KE8MQuwE2yA
class NumMatrix {
    vector<vector<int>> v;
public:
    NumMatrix(vector<vector<int>>& matrix) : v(matrix) {
        for (auto i = 0; i < matrix.size(); ++i) {
            for (auto j = 0; j < matrix[0].size(); ++j) {
                if (i > 0) v[i][j] += v[i-1][j];
                if (j > 0) v[i][j] += v[i][j-1];
                if (i > 0 && j > 0) v[i][j] -= v[i-1][j-1];
                // cout << matrix[i][j] << " ";
            }
            // cout << "\n";
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        auto ans{v[row2][col2]};
        if (row1 > 0) ans -= v[row1-1][col2];
        if (col1 > 0) ans -= v[row2][col1-1];
        if (row1 > 0 && col1 > 0) ans += v[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */