class Solution {
public:
    // 2D extension of 1D problem (solution is similar but in 2D):
    // https://leetcode.com/problems/subarray-sum-equals-k/
    // O(m^2*n) time, O(mn) space
    // slight optimization, since we only care about the count, if m > n, we can transpose then run the algo 
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // prefixSum[i][j] += matrix[0][0] + ... + matrix[0][j] + ... + matrix[i][0] + ... + matrix[i][j]
        vector<vector<int>> prefixSum(matrix);
        int m = matrix.size();
        int n = matrix[0].size();
        for (auto i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefixSum[i][j] += (i-1 >= 0 ? prefixSum[i-1][j] : 0)
                                    + (j-1 >= 0 ? prefixSum[i][j-1] : 0)
                                    - ((i-1 >= 0 && j-1 >= 0) ? prefixSum[i-1][j-1] : 0);
            }
        }
        int ans = 0;
        
        // iterate across col for a given range of rows
        for (int r2 = 0; r2 < m; ++r2) {
            for (int r1 = 0; r1 <= r2; ++r1) { // note the equality here; we also want to check range [k1, k1]
                // for each range [r1, r2], 
                // initialize count map with base case (1 prefix sum of 0)
                unordered_map<int,int> count{{0,1}};
                for (int c = 0; c < n; ++c) {
                    int cur = prefixSum[r2][c] - (r1 > 0 ? prefixSum[r1-1][c] : 0);
                    // given cur and target, we want target = cur - diff
                    // we are looking for diff := cur - target
                    if (count.find(cur - target) != count.end()) {
                        ans += count[cur - target];
                    }
                    // update our state
                    ++count[cur];
                }
            }
        }
        return ans;
    }
};