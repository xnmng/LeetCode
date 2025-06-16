class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int prev = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            ans = max(ans, nums[i] - prev);
            prev = min(prev, nums[i]);
        }
        return ans <= 0 ? -1 : ans;
    }
};