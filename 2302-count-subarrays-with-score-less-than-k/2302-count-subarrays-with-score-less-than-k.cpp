class Solution {
public:
    // similar to https://leetcode.com/problems/subarray-product-less-than-k/
    // challenge comes when we are trying to update the score:
    // to add a new number into the subarray, 
    // - add the current subarray prefix sum
    // - add the product of the new number of elements with the new number
    // - update the prefix (for future iterations)
    //
    // (to remove a number from the subarray just do the steps in reverse)
    //
    // alternatively, we can count subarrays with score more than k and subtract with total subarrays
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long left = 0;
        long long right = 0;
        long long prefix = 0;
        long long cur = 0;
        int n = nums.size();
        while (right < n) {
            cur = cur + prefix + (right - left + 1) * nums[right];
            prefix += nums[right];
            while (cur >= k) {
                prefix -= nums[left];
                cur = cur - nums[left] * (right - left + 1) - prefix;
                ++left;
            }
            ans += right - left + 1;
            ++right;
        }
        return ans;
    }
};