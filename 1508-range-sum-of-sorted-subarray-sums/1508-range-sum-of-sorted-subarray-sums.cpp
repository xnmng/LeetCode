class Solution {
public:
    // note: brute force actually works...
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int modulo = 1e9 + 7;
        vector<int> v;
        v.reserve(n * (n+1) / 2);
        for (auto i = 0; i < n; ++i) {
            int sum = 0;
            for (auto j = i; j < n; ++j) {
                sum = (sum + nums[j]) % modulo;
                v.emplace_back(sum);
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        // 1-based indexing
        for (int i = left-1; i < right; ++i) {
            ans = (ans + v[i]) % modulo;
        }
        return ans;
    }
};