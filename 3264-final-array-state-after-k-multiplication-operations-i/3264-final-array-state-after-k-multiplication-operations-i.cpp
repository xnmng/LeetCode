class Solution {
public:
    // just brute force, nothing special
    // can also sort and use pq, but constraints small enough that brute force works
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for (int i = 0; i < k; ++i) {
            int index = 0;
            for (int j = 0; j < n; ++j) {
                if (nums[index] > nums[j]) index = j;
            }
            nums[index] *= multiplier;
        }
        return nums;
    }
};