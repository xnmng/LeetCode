class Solution {
public:
    // since we want k OR (k+1), the 0th bit of nums[i] cannot be 0
    // since numbers are all prime, just check that number is 2. 
    // if it is, set to -1
    //
    // for a given number, the smallest ans is the number in binary,
    // go through the number backwards, and find the last 1 in the sequence of 1's
    // e.g. 11111 becomes 01111, 10101011, becomes 10101001
    //      ^             ^            ^                 ^
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums);
        for (int& i : nums) {
            if (i == 2) {
                i = -1;
                continue;
            }
            for (int j = 0; j < 32 && (1 << j) <= i; ++j) {
                if ((1 << (j + 1)) > i || 
                    ((1 << (j + 1)) & i) == 0) {
                    i = i ^ (1 << j);
                    break;
                }
            }
        }
        return nums;
    }
};