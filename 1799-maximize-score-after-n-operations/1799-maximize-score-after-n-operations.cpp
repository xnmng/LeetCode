class Solution {
private:
    int dfs(vector<int>& nums, vector<int>& dp, int state, int iter) {
        if (dp[state] > 0) return dp[state];
    
        auto n{nums.size()};
        int newState;
        for (auto i = 0; i < n; ++i) {
            for (auto j = i+1; j < n; ++j) {
                if ((1 << i) & state || (1 << j) & state) continue;
                newState = state | (1 << i) | (1 << j);
                // cout << "gcd of " << nums[i] << " and " << nums[j] 
                //     << " is " << __gcd(nums[i], nums[j]) << "\n";
                dp[state] = max(
                    dp[state], 
                    iter * __gcd(nums[i], nums[j]) + dfs(nums, dp, newState, iter+1)
                );
            }
        }
        
        return dp[state];
    }
public:
    int maxScore(vector<int>& nums) {
        vector<int> dp(1<<nums.size(), 0);
        dfs(nums, dp, 0, 1);
        // for (auto i : dp) cout << i << " ";
        // cout << "\n";
        return dp.front();
    }
};