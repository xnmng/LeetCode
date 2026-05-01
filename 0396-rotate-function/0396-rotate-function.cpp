class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        auto sum{0};
        auto cur{0};
        auto n{nums.size()};
        for (auto i = 0; i < n; ++i) {
            sum += nums[i];
            cur += i * nums[i];
        }
        auto ans{cur};
        for (auto i = 1; i < n; ++i) {
            cur += sum;
            cur -= n * nums[n-i];
            ans = max(cur, ans);
        }
        return ans;
    }
};