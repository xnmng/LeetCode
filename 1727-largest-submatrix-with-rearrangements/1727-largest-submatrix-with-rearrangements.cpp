// https://leetcode.com/problems/largest-submatrix-with-rearrangements/solution/
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> prev;
        vector<pair<int,int>> cur;
        vector<bool> seen;
        prev.reserve(n);
        cur.reserve(n);
        seen.reserve(n);
        // initialize prev
        for (auto i = 0; i < n; ++i) {
            if (matrix[0][i] == 1) {
                prev.emplace_back(1, i);
            }
        }
        int ans = prev.size();
        for (auto i = 1; i < m; ++i) {
            cur.clear();
            seen = vector<bool>(n, false); 
            // increase streak if possible
            for (auto& [val, index] : prev) {
                if (matrix[i][index] == 1) {
                    cur.emplace_back(val+1, index);
                    seen[index] = true;
                }
            }
            // add new streak
            for (auto j = 0; j < n; ++j) {
                if (!seen[j] && matrix[i][j] == 1) {
                    cur.emplace_back(1, j);
                }
            }
            // update ans
            for (auto k = 0; k < cur.size(); ++k) {
                ans = max(ans, (k+1) * cur[k].first);
            }
            swap(cur, prev);
        }
        return ans;
    }
};