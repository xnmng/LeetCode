class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            ans.emplace_back(sum);
            sum += nums[i];
        }
        sum = 0;
        for (int i = n-1; i >= 0; --i) {
            if (ans[i] - sum < 0) ans[i] = sum - ans[i];
            else ans[i] -= sum;
            sum += nums[i];
        }
        return ans;
    }
};