class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp{0};
        vector<int> next;
        int m = triangle.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                // cout << triangle[i][j] << "\n";
                next.emplace_back(min((j == 0 ? INT_MAX : dp[j-1]), 
                                (j < dp.size() ? dp[j] : INT_MAX)) + triangle[i][j]);
            }
            swap(dp, next);
            // for (int i : dp) cout << i << " ";
            // cout << "\n";
            next.clear(); 
        }
        int ans = INT_MAX;
        for (int i : dp) ans = min(ans, i);
        return ans;
    }
};