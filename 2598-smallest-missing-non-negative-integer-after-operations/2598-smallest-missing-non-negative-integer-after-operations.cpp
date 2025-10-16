class Solution {
public:
    // any k can be transformed to k + m * value
    // group all numbers k into groups k % value
    // iterate from 0, check its respective group, decrement by 1
    // until you reach a group with 0, then return ans
    //
    // O(n) time, O(value) space
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> v(value, 0);
        int cur;
        for (int i : nums) {
            cur = (i % value + value) % value;
            ++v[cur];
        }
        int ans = 0;
        while (v[ans % value] > 0) {
            --v[ans % value];
            ++ans;
        }
        return ans;
    }
};