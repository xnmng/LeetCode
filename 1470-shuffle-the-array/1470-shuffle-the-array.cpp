class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for (auto i = 0; i < n; ++i) {
            nums[i] = nums[i] << 16;
            nums[i] |= nums[i + n];
        }
        for (auto i = n-1; i >= 0; --i) {
            nums[2 * i + 1] = nums[i] & static_cast<int>(pow(2, 16) - 1);
            nums[2 * i] = nums[i] >> 16;
        }
        return nums;
    }
};