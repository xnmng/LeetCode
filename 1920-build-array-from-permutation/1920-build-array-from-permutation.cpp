class Solution {
public:
    // to do this in place, find some way to encode the input inside the original, then transform it 
    // 
    // looking at the constraints, we can multiply the res * 1001, then later divide by 1001
    // O(n) 2 pass but constant space
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[i] += 1000 * (nums[nums[i]] % 1000);
        }
        for (int i = 0; i < n; ++i) {
            nums[i] /= 1000;
        }
        return nums;
    }
};