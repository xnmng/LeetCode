class Solution {
    // int dfs(vector<int>& cost, vector<int>& dp, int index) {
    //     if (index >= cost.size()) return 0;
    //     if (dp[index] == INT_MAX) {
    //         dp[index] = cost[index] + min(dfs(cost, dp, index+1), dfs(cost, dp, index+2));
    //     }
    //     return dp[index];
    // }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // dp[i] = cost[i] + min(dp[i+1], dp[i+2])
        // vector<int> dp(cost.size(), INT_MAX);
        // dfs(cost, dp, 0);
        // dfs(cost, dp, 1);
        int prevprev = cost[0];
        int prev = cost[1];
        int temp;
        for (auto i = 2; i < cost.size(); ++i) {
            temp = cost[i] + min(prevprev, prev);
            prevprev = prev;
            prev = temp;
        }
        return min(prevprev, prev);
        // return min(dp[0], dp[1]);
    }
};

// 10 15 20 10 12 done
// 10 15 30 25  