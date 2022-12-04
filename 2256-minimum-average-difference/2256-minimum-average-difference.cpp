class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        auto sum{0L};
        for (auto i : nums) {
            sum += i;
        }
        auto cur{0L};
        auto n{nums.size()};
        auto ans{-1};
        auto val{INT_MAX};
        auto next{0};
        for (auto i = 0; i < n-1; ++i) {
            cur += nums[i];
            next = abs(static_cast<int>((cur/(i+1)) - ((sum - cur)/(n-i-1))));
            // cout << i << " " << next << "\n";
            if (val > next) {
                ans = i;
                val = next;
            }
            // cout << ans << " " << val << "\n\n";
        }
        return val <= static_cast<int>(sum/n) ? ans : n-1;
    }
};

// [1]
// [4,2,0]
// [0,0,0,0,0]