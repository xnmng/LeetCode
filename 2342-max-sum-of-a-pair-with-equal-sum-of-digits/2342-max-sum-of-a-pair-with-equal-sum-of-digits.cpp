class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int,int> mp;
        int sum;
        for (int i : nums) {
            sum = helper(i);
            if (mp.count(sum) > 0) {
                ans = max(ans, mp[sum] + i);
            }
            mp[sum] = max(mp[sum], i);
        }
        return ans;
    }

    int helper(int i) {
        int ans = 0;
        while (i > 0) {
            ans += i % 10;
            i /= 10;
        }
        return ans;
    }
};