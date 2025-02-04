class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int sum = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                sum += nums[i];
            }
            else sum = nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};