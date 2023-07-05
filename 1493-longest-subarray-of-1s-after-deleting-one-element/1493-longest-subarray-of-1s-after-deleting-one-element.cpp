class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto ans{0};
        auto prev2{-1};
        auto prev1{-1};
        auto prev{-1};
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                prev2 = prev1;
                prev1 = prev;
                prev = i;
                // cout << prev2 << " " << prev1 << " " << prev << "\n";
                ans = max(prev - prev2 - 2, ans);
            }
        }
        prev2 = prev1;
        prev1 = prev;
        prev = nums.size();
        // cout << prev2 << " " << prev1 << " " << prev << "\n";
        // cout << prev - prev2 - 3 << "\n";
        ans = max(prev - prev2 - 2, ans);
        return min(ans, static_cast<int>(nums.size()-1)); // handle edge case
    }
};