class Solution {
public:
    // https://leetcode.com/problems/count-the-number-of-fair-pairs/solutions/3174615/very-simple-easy-to-understand-solution
    // if first number is x, next number must be in the range [lower - x, upper - x]
    // add numbers in this range to ans
    // (note requirement on i < j; we can achieve this by only doing our search on indexes > i)
    // O(nlogn) time, O(1) space
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // i + x >= lower
            // x >= lower - i
            auto itr1 = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            // i + x <= upper
            // x <= upper - i
            auto itr2 = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            ans += distance(itr1, itr2);
        }
        return ans;
    }
};