class Solution {
public:
    // binary search for q
    // O((n+q) * logq) time, O(n) space
    // O(logq) time for binary search, each iteration is O(n + q) time
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int> v(n + 1, 0);

        int left = 0;
        int right = q;
        int mid;
        int ans = INT_MAX;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (helper(mid, nums, queries, v)) {
                ans = min(ans, mid);
                right = mid - 1;
            } else left = mid + 1;
        }
        return ans == INT_MAX ? -1 : ans;
    }

    bool helper(int mid, vector<int>& nums, vector<vector<int>>& queries, vector<int>& v) {
        fill(v.begin(), v.end(), 0); // reset
        int n = nums.size();
        for (int i = 0; i < mid; ++i) {
            v[queries[i][0]] -= queries[i][2];
            if (queries[i][1] + 1 < n) v[queries[i][1] + 1] += queries[i][2];
        }
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += v[i];
            if (nums[i] + cur > 0) return false;
        }
        return true;
    }
};