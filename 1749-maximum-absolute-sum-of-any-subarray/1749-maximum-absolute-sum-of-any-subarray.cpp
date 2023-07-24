class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        auto ans{0};
        auto cur{0};
        for (auto& i : nums) {
            cur += i;
            if (cur < 0) cur = 0;
            else ans = max(ans, cur);
        }
        cur = 0;
        for (auto& i : nums) {
            cur += i;
            if (cur > 0) cur = 0;
            else ans = max(ans, -1 * cur);
        }
        return ans;
    }
};