// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/1395121/4-Minutes-Read-Simple-No-Brainer-Recursion-+-Memoization
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/780880/DP-with-picture-(Burst-Balloons)
class Solution {
private:
    int dfs(vector<vector<int>>& dp, vector<int>& cuts, int left, int right) {
        if (dp[left][right] != -1) return dp[left][right];
        dp[left][right] = INT_MAX;
        for (auto i = left+1; i < right; ++i) {
            dp[left][right] = min(dp[left][right], 
                      cuts[right] - cuts[left] + dfs(dp, cuts, left, i) + dfs(dp, cuts, i, right));
        }
        if (dp[left][right] == INT_MAX) dp[left][right] = 0;
        return dp[left][right];
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size()+1, vector<int>(cuts.size()+1, -1));
        return dfs(dp, cuts, 0, cuts.size()-1);
    }
};
// 6448
// [3309,5839,4626,4670,5971,6426,5561,2835,3474,3539,1880,4123,571,3128,4075,5896,5020,207,3529,5435,2440,3993,5885,2145,2422,3379,949,248,2627,3392,1795,4893,4415,3282,1776,5520,2199,57,3098,968,1310,4870,5503,1336,636,4747,1371,854,2882,5976,5409,3173,5256,4960,2662,508,1625,304,5867,5939,2499,2845,744,6252,5320,3552,4790,6112,3535,4783,6194,4248,1886,3264,3221,407,1954,1731,3318,6213,1299,5206,3753]