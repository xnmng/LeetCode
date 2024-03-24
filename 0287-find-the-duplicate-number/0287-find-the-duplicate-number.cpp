class Solution {
public:
    // clarification: there is 1 repeated number, but it can be repeated >1 times
    
    // set -1 flag into input arr
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i])] < 0) return abs(nums[i]);
            nums[abs(nums[i])] *= -1;
        }
        return -1; // should not happen; pigeonhole principle
    }
};