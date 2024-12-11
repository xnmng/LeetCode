class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        while (right < n) {
            while (left < right && nums[right] - nums[left] > 2 * k) {
                ++left;
            }
            ans = max(ans, right - left + 1);
            ++right;
        }
        return ans;
    }
};