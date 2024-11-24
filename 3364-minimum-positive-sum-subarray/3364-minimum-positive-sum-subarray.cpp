class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        int sum;

        for (int i = l; i <= r; ++i) {
            sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += nums[j];
            }
            if (sum > 0) ans = min(ans, sum);
            for (int j = i; j < n; ++j) {
                sum += nums[j] - nums[j - i];
                if (sum > 0) ans = min(ans, sum);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};