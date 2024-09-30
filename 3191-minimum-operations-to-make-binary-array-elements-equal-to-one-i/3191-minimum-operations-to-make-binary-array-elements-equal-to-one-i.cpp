class Solution {
public:
    // simulate the process
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n-2; ++i) {
            if (nums[i] == 0) {
                ++ans;
                for (int j = 0; i + j < n && j < 3; ++j) {
                    nums[i+j] ^= 1;
                }
            }
        }
        
        if (nums[n-1] == 0 || nums[n-2] == 0) return -1;
        return ans;
    }
};