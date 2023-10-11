// https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/discuss/4154964/Greedy-Bit-Moves
// https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/discuss/4143971/JavaC++Python-Count-Bits
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> v(32);
        // counting sort the bits
        for (auto i : nums) {
            int index = 0;
            while (i > 0) {
                v[index] += i % 2;
                i /= 2;
                ++index;
            }
        }
        
        long ans = 0;
        long modulo = 1e9 + 7;
        long cur;
        while (k > 0) {
            --k;
            cur = 0;
            for (auto i = 0; i < 32; ++i) {
                if (v[i]) {
                    cur += 1 << i;
                    --v[i];
                }
            }
            ans = (ans + cur * cur) % modulo;
        }
        return ans;
    }
};