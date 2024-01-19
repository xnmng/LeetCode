class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int cur = 0;
        int count = 0;
        int n = nums.size();
        vector<int> update(n+1, 0);
        for (auto i = 0; i < n; ++i) {
            cur += update[i];
            // we need to perform a flip
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