class Solution {
public:
    // why we directly maximize the difference :
    
    // Alice is starting first, and her goal is to maximize the difference, 
    // so we always take the maximum between the two options. 
    // If Bob was starting first, we would take the minimum between the two options.
    
    // We don't need to keep track of turns because, at the time of Alice, 
    // we are maximizing aliceCurrentPick - (bobNextPick onwards), which will inherently minimize bobNextPick. 
    // At Bob's turn in recursion, we are again taking maximum of two options, 
    // because that will be negated on a layer above, hence playing the optimal move to reduce the difference.
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int sum = 0;
        for (auto i : stones) sum += i;
        return dfs(stones, 0, n-1, dp, sum);
    }
    
    int dfs(vector<int>& stones, int left, int right, vector<vector<int>>& dp, int sum) {
        if (left == right) return 0;
        if (dp[left][right] == INT_MAX) {
            int val = max(sum - stones[left] - dfs(stones, left+1, right, dp, sum - stones[left]), 
                          sum - stones[right] - dfs(stones, left, right-1, dp, sum - stones[right])); 
            dp[left][right] = val;
        }
        return dp[left][right];
    }
};