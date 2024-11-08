class Solution {
public:
    // largest XOR happens when we select k to always be 2^maxBit - 1
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n);
        int cur = 0;
        for (int i : nums) cur ^= i;
        int k = pow(2, maximumBit) - 1;
        for (int i = n-1; i >= 0; --i) {
            ans.emplace_back(cur ^ k);
            cur ^= nums[i];
        }
        return ans;
    }
};