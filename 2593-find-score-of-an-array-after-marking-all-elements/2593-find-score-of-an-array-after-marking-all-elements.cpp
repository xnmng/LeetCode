class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        v.reserve(n);
        for (auto i = 0; i < n; ++i) {
            v.emplace_back(nums[i], i);
        }
        sort(v.begin(), v.end());
        vector<bool> s(n, false);
        long long ans{0};
        for (auto& [value, index] : v) {
            if (s[index]) continue;
            ans += value;
            s[index] = true;
            if (index + 1 < n) s[index + 1] = true;
            if (index - 1 >= 0) s[index - 1] = true;
        }
        return ans;
    }
};