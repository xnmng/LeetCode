class Solution {
public:
    //
    // naive; O(n) time but O(n) space: just create new nums, generate expected output
    // also naive; O(1) space (in-place) but O(n^2) time: right rotate when placing new element
    // 
    // incorrect solution: just find mismatching indexes and swap
    //      use test case below to understand why it doesnt work
    //      (we will end up swapping some number out of order, 
    //      and the algo will continue as usual, breaking the ordering invariant)
    // 
    // we could use O(n) space (or n/2, but still O(n) space)
    // 
    // unsure if O(n) in place solution exists
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pos = 0;
        int neg = 1;
        for (auto i : nums) {
            if (i < 0) {
                ans[neg] = i;
                neg += 2;
            }
            else {
                ans[pos] = i;
                pos += 2;
            }
        }
        return ans;
    }
};
// [28,-41,22,-8,-37,46,35,-9,18,-6,19,-26,-37,-10,-9,15,14,31]