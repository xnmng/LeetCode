class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;
        for (auto i : nums) {
            if (mp[k-i] > 0) {
                --mp[k-i];
                ++ans;
            } else {
                ++mp[i];
            }
        }
        return ans;
    }
};