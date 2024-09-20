class Solution {
public:
    // constraints small, just sort and simulate the process
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double ans = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n/2; ++i) {
            ans = min(ans, (double)(nums[i] + nums[n - 1 - i]) / 2);
        }
        return ans;
    }
};