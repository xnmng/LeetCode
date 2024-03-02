class Solution {
public:
    // 2 pointers, add largest abs value square to ans
    // dont really need to reverse, just keep track of the desired location then store directly
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0;
        int right = n-1;
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                ans[right - left] = (nums[left] * nums[left]);
                ++left;
            } else {
                ans[right - left] = (nums[right] * nums[right]);
                --right;                
            }
        }
        return ans;
    }
};