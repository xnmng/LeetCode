class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = n - 2; i >= 0; --i) {
            while (nums[i] > nums[i + 1]) {
                
                int k = getLargestDivisor(nums[i]);
                ++ans;
                if (k == nums[i] || k == -1) return -1;
                nums[i] /= k;
            }
        }
        return ans;
    }

    int getLargestDivisor(int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                return x / i;
            }
        }
        return -1;
    }
};
// [9,2]
// [288,7]