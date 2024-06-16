class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long cur = 0;
        int ans = 0;
        int i = 0;
        int len = nums.size();
        while (i < len) {
            if (cur >= n) break;
            if (cur + 1 >= nums[i]) {
                cur += nums[i];
                ++i;
            } else {
                ++ans;
                cur += cur + 1;
            }
        }
        while (cur < n) {
            ++ans;
            cur += cur + 1;
        }
        return ans;
    }
};
// [1,2,31,33]
// 2147483647
