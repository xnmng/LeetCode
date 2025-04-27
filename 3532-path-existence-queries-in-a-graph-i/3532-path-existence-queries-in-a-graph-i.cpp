class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, 
                                        int maxDiff, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<bool> ans;
        ans.reserve(m);
        vector<int> group(n, 0);
        for (int i = 1; i < n; ++i) {
            // assume its in the same group, unless it exceeds maxDiff
            // then increase the group ID
            group[i] = group[i-1];
            if (nums[i] - nums[i-1] > maxDiff) {
                ++group[i];
            }
        }
        for (int i = 0; i < m; ++i) {
            ans.emplace_back(group[queries[i][0]] == group[queries[i][1]]);
        }
        return ans;
    }
};