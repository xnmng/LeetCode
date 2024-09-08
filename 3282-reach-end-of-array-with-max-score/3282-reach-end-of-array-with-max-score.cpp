class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        long long cur = nums[0];
        int index = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= cur) {
                ans += cur * (i - index);
                cur = nums[i];
                index = i;
            }
        }
        ans += cur * (n - 1 - index);
        return ans;
    }
};