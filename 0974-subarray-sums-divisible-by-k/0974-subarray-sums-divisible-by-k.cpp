class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> v(k, 0);
        v[0] = 1; // handle case where first sum itself is a multiple of k
        auto sum{0};
        auto ans{0};
        for (auto i : nums) {
            // Take modulo twice to avoid negative remainders.
            sum = ((sum + i) % k + k) % k;
            ans += v[sum];
            ++v[sum];
        }
        return ans;
    }
};