class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp; // (sum, freq)
        mp[0] = 1;
        int cur = 0;
        int ans = 0;
        for (int i : nums) {
            cur += i;
            ans += mp[cur - goal];
            ++mp[cur];
        }
        return ans;
    }
};