class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long modulo = 1e9+7;
        long ans = 0;
        unordered_map<long, vector<long>> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].emplace_back(i);
        }
        int left;
        int right;
        vector<long>::iterator itr;
        long num;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue;
            num = nums[i] * 2;
            itr = lower_bound(mp[num].begin(), mp[num].end(), i);
            left = distance(mp[num].begin(), itr);
            right = mp[num].size() - left;
            ans = ((left * right) + ans) % modulo;
        }
        // handle edge case 0 separately
        // reuse num variable
        // num = (mp[0].size() * (mp[0].size() - 1)) % modulo;
        // num = (num * (mp[0].size() - 2)) % modulo;
        // ans += num / 6;
        num = (mp[0].size() * (mp[0].size() - 1) * (mp[0].size() - 2) / 6) % modulo;
        ans = (ans + num) % modulo;
        return ans;
    }
};