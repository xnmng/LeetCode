// https://leetcode.com/problems/01-matrix/discuss/1369741/C++JavaPython-BFS-DP-solutions-with-Picture-Clean-and-Concise-O(1)-Space
class Solution {
public:
    // dp solution O(mn) time (2 pass), O(1) space
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m(mat.size());
        int n(mat[0].size());
        int left, right, up, down;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) continue;
                left = m+n;
                up = m+n;
                if (i > 0) up = mat[i-1][j];
                if (j > 0) left = mat[i][j-1];
                mat[i][j] = min(up, left) + 1;
            }
        }
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (mat[i][j] == 0) continue;
                down = m+n;
                right = m+n;
                if (i < m-1) down = mat[i+1][j];
                if (j < n-1) right = mat[i][j+1];
                mat[i][j] = min(mat[i][j], min(right, down) + 1);
            }
        }
        
        return mat;
    }
};
// [[0,1,0,1,1],[1,1,0,0,1],[0,0,0,1,0],[1,0,1,1,1],[1,0,0,0,1]]