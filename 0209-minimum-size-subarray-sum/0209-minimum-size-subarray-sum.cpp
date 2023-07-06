class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        auto ans{INT_MAX};
        auto left{0};
        auto right{0};
        auto sum{0};
        while (right < nums.size()) {
            sum += nums[right];
            ++right;
            while (sum >= target && left <= right) {
                ans = min(ans, right - left);
                sum -= nums[left];
                ++left;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};