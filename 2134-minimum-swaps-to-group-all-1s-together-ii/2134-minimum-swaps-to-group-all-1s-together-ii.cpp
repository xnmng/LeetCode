class Solution {
public:
    // sliding window
    // find the maximum number of 1's we can have in a contiguous window of size 1_count
    // to handle circular behaviour, either append original arr to it (O(n) space)
    // or use modulo operator (O(1) space)
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (auto i : nums) {
            if (i == 1) ++total;
        }
        
        int count = 0;
        for (int i = 0; i < total; ++i) {
            if (nums[i] == 1) ++count;
        }
        int ans = total;
        // check all n possible windows
        for (int i = 0; i < n; ++i) {
            ans = min(ans, total - count);
            // prepare for next iteration
            // remove left of sliding window 
            //      (aka cur start position, index i)
            // add right of sliding window 
            //      (aka next end position, index i+1+total-1, or just i+total)
            if (nums[i] == 1) --count;
            if (nums[(i + total) % n] == 1) ++count;
        }
        
        return ans;
    }
};