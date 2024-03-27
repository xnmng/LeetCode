class Solution {
public:
    // has to be strictly less than k
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // based on input constraints
        int ans = 0;
        int cur = 1;
        int left = 0;
        int right = 0;
        int n = nums.size();
        while (right < n) {
            // cout << left << " " << right << " " << n << "\n";
            cur *= nums[right];
            while (cur >= k) {
                cur /= nums[left];
                ++left;
            }
            ans += right - left + 1;
            ++right;
        }
        return ans;
    }
};
// [1,1,1]
// 1