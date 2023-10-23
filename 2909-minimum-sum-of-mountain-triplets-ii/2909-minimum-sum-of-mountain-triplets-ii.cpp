class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MAX);
        for (auto i = 0; i < n; ++i) {
            left[i] = nums[i];
            if (i > 0) left[i] = min(left[i], left[i-1]);
        }
        // optimization: we can do the computation of ans on the 2nd pass of right
        // no need to store right vec
        for (auto i = n-1; i >= 0; --i) {
            right[i] = nums[i];
            if (i+1 < n) right[i] = min(right[i], right[i+1]);            
        }
        int ans = INT_MAX;
        for (auto i = 1; i < n-1; ++i) {
            if (nums[i] > left[i] && nums[i] > right[i]) {
                ans = min(ans, left[i] + nums[i] + right[i]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};