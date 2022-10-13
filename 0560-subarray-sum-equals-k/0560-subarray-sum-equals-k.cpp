// https://leetcode.com/problems/subarray-sum-equals-k/discuss/1759909/C++or-Full-explained-every-step-w-Dry-run-or-O(n2)-greater-O(n)-or-Two-approaches
class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        auto sum{0};
        auto ans{0};
        for (auto i : nums) {
            sum += i;
            if (mp.find(sum-target) != mp.end()) {
                ans += mp[sum-target];
            }
            if (sum == target) ++ans;
            ++mp[sum];
        }
        return ans;
    }
};