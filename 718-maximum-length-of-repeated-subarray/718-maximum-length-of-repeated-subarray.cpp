class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        auto m{nums1.size()};
        auto n{nums2.size()};
        // cout << m << " " << n << "\n";
        vector<vector<int>> dp(m, vector<int>(n, 0));
        auto ans{0};
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (ans == min(m,n)) return ans;
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1;
                }
                if (i > 0 && j > 0 && nums1[i-1] == nums2[j-1]) {
                    dp[i][j] += dp[i-1][j-1];                    
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

// compare against previous index (nums1[i-1] == nums2[j-1]), NOT previous dp value! (dp[i-1][j-1] > 0)
// [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
// [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0]