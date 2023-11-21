class Solution {
    int reverse(int i) {
        int ans = 0;
        while (i != 0) {
            ans *= 10;
            ans += i % 10;
            i /= 10;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
        // nums[i] - rev(nums[i]) == nums[j] - rev(nums[j]) (rewrite the condition)
        unordered_map<int,int> mp;
        int modulo = 1e9 + 7;
        int ans = 0;
        for (auto i : nums) {
            ans = (ans + mp[i - reverse(i)]) % modulo;
            ++mp[i - reverse(i)];
        }
        return ans;
    }
};