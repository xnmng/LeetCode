class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto ans{0};
        auto cur{0};
        auto prev{0};
        for (auto& i : nums) {
            if (i == 1) ++cur;
            else {
                ans = max(ans, cur + prev);
                prev = cur;
                cur = 0;
            }
        }
        ans = max(ans, cur + prev);
        return min(ans, static_cast<int>(nums.size()-1)); // edge case; arr is all 1's
    }
};