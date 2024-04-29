class Solution {
public:
    // optimization: xor k with all of nums xor, 
    // then just check for number of '1' bits
    int minOperations(vector<int>& nums, int k) {
        int cur = k;
        for (auto i : nums) cur ^= i;
        int ans = 0;
        while (cur != 0) {
            if (cur % 2 == 1) {
                ++ans;
            }
            cur /= 2;
        }
        return ans;
    }
};