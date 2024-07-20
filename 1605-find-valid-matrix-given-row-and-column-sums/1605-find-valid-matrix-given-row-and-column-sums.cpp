class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rowSum[i] == 0) break;
                ans[i][j] = min(colSum[j], rowSum[i]);
                colSum[j] -= ans[i][j];
                rowSum[i] -= ans[i][j];
            }
        }
        return ans;
    }
};
// [14,9]
// [6,9,8]
