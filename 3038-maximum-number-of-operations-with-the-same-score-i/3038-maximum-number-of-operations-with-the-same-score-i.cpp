class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int ans = 1;
        int sum = nums[0] + nums[1];
        int n = nums.size();
        for (int i = 2; i < n; i += 2) {
            if (sum != nums[i] + nums[i+1]) break;
            ++ans;
        }
        return ans;
    }
};