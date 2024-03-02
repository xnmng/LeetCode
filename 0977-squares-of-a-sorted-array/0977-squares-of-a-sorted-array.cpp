class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n);
        int left = 0;
        int right = n-1;
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                ans.emplace_back(nums[left] * nums[left]);
                ++left;
            } else {
                ans.emplace_back(nums[right] * nums[right]);
                --right;                
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};