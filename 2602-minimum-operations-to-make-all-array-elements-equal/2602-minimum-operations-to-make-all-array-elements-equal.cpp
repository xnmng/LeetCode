// https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/discuss/3341978/Prefix-Sum
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long long> prefixSum{0};
        for (auto i = 0; i < nums.size(); ++i) {
            prefixSum.emplace_back(prefixSum.back() + nums[i]);
        }
        vector<long long> ans;
        for (auto q : queries) {
            // upper_bound returns iterator to first element > q
            auto index{upper_bound(nums.begin(), nums.end(), q) - nums.begin()};
            ans.emplace_back(q * index - prefixSum[index] 
                             + prefixSum.back() - prefixSum[index] - q * (nums.size() - index));
        }
        return ans;
    }
};