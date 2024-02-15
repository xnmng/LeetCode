class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans = -1;
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            if (i >= 2 && sum > nums[i]) {
                ans = sum + nums[i];
            }
            sum += nums[i];
        }
        return ans;
    }
};