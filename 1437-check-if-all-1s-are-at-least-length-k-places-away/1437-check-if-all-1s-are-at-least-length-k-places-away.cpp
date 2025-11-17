class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        auto prev{-k - 1};
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                // cout << i - prev - 1 << "\n";
                if (i - prev - 1 < k) return false;
                prev = i;
            }
        }
        return true;
    }
};