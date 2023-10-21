// https://leetcode.com/problems/constrained-subsequence-sum/solution/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        // Let dp[i] be the solution for the prefix of the array that ends at index i, if the element at index i is in the subsequence.
        // dp[i] = nums[i] + max(0, dp[i-k], dp[i-k+1], ..., dp[i-1])
        int ans = INT_MIN;
        // monotonic; front contains largest sum so far
        deque<pair<int,int>> dq; // <sum, index>
        int cur;
        for (auto i = 0; i < n; ++i) {
            while (!dq.empty() && i - dq.front().second > k) dq.pop_front();
            cur = nums[i] + (dq.empty() ? 0 : dq.front().first);
            ans = max(ans, cur);
            while (!dq.empty() && dq.back().first < cur) dq.pop_back();
            if (cur > 0) dq.emplace_back(cur, i);
        }
        return ans;
    }
};