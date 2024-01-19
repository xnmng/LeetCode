class Solution {
public:
    // idea:
    //      to flip nums into all 1's, we perform the flips from left to right
    //      
    //      we dont actually need to perform the flips (which take O(k) time)
    //      instead, we just track the 'flip count', as well as when the flip count ends
    //      which is stored inside the update vector
    int minKBitFlips(vector<int>& nums, int k) {
        int cur = 0;
        int count = 0;
        int n = nums.size();
        vector<int> update(n+1, 0); // +1 trick to handle edge case; doesnt change TC or SC
        for (auto i = 0; i < n; ++i) {
            cur += update[i];
            // we need to perform a flip if the parity is 0
            if ((nums[i] + cur) % 2 == 0) {
                // unable to make flips, return -1
                if (i + k - 1 >= n) return -1;
                ++cur;
                ++count;
                update[i+k] = -1;
            }
        }
        return count;
    }
};