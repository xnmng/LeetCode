class Solution {
public:
    // note that we dont actually need all the indexes
    // we just need to know if our range has k counts
    // O(n) time, O(1) space
    // can reuse k as the count
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int len;
        int maximum = *max_element(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        while (right < n) {
            if (nums[right] == maximum) --k;
            while (k == 0) {
                if (nums[left] == maximum) ++k;
                ++left;
            }
            ans += left;
            ++right;
        }
        return ans;
    }

    // // we need at least k times of the max element
    // // 
    // // determine the max element, iterate across vector and store indexes in a vector
    // //
    // // suppose we already seen the max element >= k times
    // // we can then count, given this index as the end, how many subarrays can i form?
    // // the number would be indexes[m-1-k+1] where m is number of indexes so far
    // //
    // // O(n) time, O(n) space
    // long long countSubarrays(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     long long ans = 0;
    //     vector<int> index;
    //     int len;
    //     int maximum = *max_element(nums.begin(), nums.end());
    //     for (int i = 0; i < n; ++i) {
    //         if (nums[i] == maximum) index.emplace_back(i);
    //         len = index.size();
    //         if (len >= k) {
    //             ans += index[len - k] + 1; // + 1 for current subarray
    //         }
    //     }
    //     return ans;
    // }
};