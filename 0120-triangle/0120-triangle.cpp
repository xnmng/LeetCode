class Solution {
public: 
    // can either do top down or bottom up 
    // (start from first/last row and work your way down/up)
    // O(mn) time, O(1) space (use input)
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        for (int i = m-2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += min(triangle[i+1][j], 
                                (j+1 < triangle[i+1].size() ? triangle[i+1][j+1] : INT_MAX));
            }
        }
        return triangle[0][0];
    }

    // // O(mn) time, O(n) space
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     vector<int> dp{0};
    //     vector<int> next;
    //     int m = triangle.size();
    //     for (int i = 0; i < m; ++i) {
    //         for (int j = 0; j < triangle[i].size(); ++j) {
    //             // cout << triangle[i][j] << "\n";
    //             next.emplace_back(min((j == 0 ? INT_MAX : dp[j-1]), 
    //                             (j < dp.size() ? dp[j] : INT_MAX)) + triangle[i][j]);
    //         }
    //         swap(dp, next);
    //         // for (int i : dp) cout << i << " ";
    //         // cout << "\n";
    //         next.clear(); 
    //     }
    //     int ans = INT_MAX;
    //     for (int i : dp) ans = min(ans, i);
    //     return ans;
    // }
};