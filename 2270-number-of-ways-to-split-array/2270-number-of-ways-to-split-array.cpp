class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        long left = 0;
        long right = 0;
        for (int i : nums) right += i;
        int n = nums.size();
        for (int i = 0; i < n-1; ++i) {
            left += nums[i];
            right -= nums[i];
            if (left >= right) ++ans;
        }
        return ans;
    }
};