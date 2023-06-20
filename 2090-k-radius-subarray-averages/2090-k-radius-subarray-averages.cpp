class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(), -1);
        long sum{0};
        auto left{0};
        auto center{k};
        for (auto i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (i >= 2 * k) {
                ans[center] = sum / (2 * k + 1);
                sum -= nums[left];
                ++center;
                ++left;                
            }
        }
        return ans;
    }
};