class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long count = 0;
        long sum = 0;
        long ans = 0;
        for (auto i = 0; i < n; ++i) {
            ++count;
            sum += nums[i];
            while (sum + k < nums[i] * count) {
                sum -= nums[i - count + 1];
                --count;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};