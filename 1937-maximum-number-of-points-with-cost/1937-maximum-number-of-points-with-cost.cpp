class Solution {
public:
    // standard dp; only need prev state
    // naive dp is O(mn^2) time; too slow
    // 
    // to optimize, precompute the best choice for a given index i 
    // (using prev row and prev index val - 1)
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> prev;
        for (auto i : points[0]) {
            prev.emplace_back(i);
        }
        for (int i = 1; i < m; ++i) {
            vector<long long> cur(n);
            vector<long long> left(n);
            vector<long long> right(n);
            left[0] = prev[0];
            right[n-1] = prev[n-1];
            for (int j = 1; j < n; ++j) {
                left[j] = max(prev[j], left[j-1] - 1);
            }
            for (int j = n-2; j >= 0; --j) {
                right[j] = max(prev[j], right[j+1] - 1);
            }
            
            for (int j = 0; j < n; ++j) {
                cur[j] = points[i][j] + max(left[j], right[j]);
            }
            swap(cur, prev);
        }
        long long ans = INT_MIN;
        for (auto i : prev) ans = max(ans, i);
        return ans;
    }
};