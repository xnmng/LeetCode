class Solution {
public:
    // rewriting the initial conditon,
    // j - i != nums[j] - nums[i]
    // we obtain
    // j - nums[j] != i - nums[i]
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        int diff;
        for (int i = 0; i < n; ++i) {
            diff = i - nums[i];
            ans += i - mp[diff];
            ++mp[diff];
        }
        return ans;
    }
};