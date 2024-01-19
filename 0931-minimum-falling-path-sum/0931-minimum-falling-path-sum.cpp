class Solution {
public:
    // either use O(n) space to store DP state, or use input 2D vector to store DP state
    int minFallingPathSum(vector<vector<int>>& matrix) {
        auto n{matrix.size()};
        vector<int> prev(matrix[0]);
        vector<int> cur(n);
        for (auto i = 1; i < n; ++i) {
            for (auto j = 1; j < n-1; ++j) {
                cur[j] = matrix[i][j] + min(prev[j+1], min(prev[j-1], prev[j]));
            }
            cur[0] = matrix[i][0] + min(prev[1], prev[0]);
            cur[n-1] = matrix[i][n-1] + min(prev[n-1], prev[n-2]);
            swap(prev, cur);
        }
        auto ans{INT_MAX};
        
        for (auto i : prev) ans = min(ans, i);
        return ans;
    }
};