class Solution {
public:
    // https://leetcode.com/problems/special-array-ii/editorial
    // split nums into disjoint subarrays such that each subarray is a special subarray
    // for a query to be true, its entire range should be within a subarray
    // O(M + NlogM) time, O(M) space, where M is size of nums, N is size of queries
    //
    // better solution:
    // prefix sum/sliding window + cache
    // O(M + N) time, O(M) space
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size();
        int n = queries.size();
        vector<int> prefix{0};
        vector<bool> ans;
        prefix.reserve(m);
        ans.reserve(n);
        int count = 0;
        for (int i = 1; i < m; ++i) {
            if ((nums[i] + nums[i-1]) % 2 == 0) ++count;
            prefix.emplace_back(count);
        }
        for (int i = 0; i < n; ++i) {
            ans.emplace_back(prefix[queries[i][0]] == prefix[queries[i][1]]);
        }
        // for (int i : prefix) cout << i << " ";
        // cout << "\n";
        return ans;
    }
};
// [1,4]
// [[0,1]]
// [1,1]
// [[0,1]]