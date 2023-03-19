class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        auto ans{0};
        if (nums.size() < 3) return ans;
        int diff{nums[1] - nums[0]};
        int count{1};
        for (auto i = 2; i < nums.size(); ++i) {
            if (nums[i] - nums[i-1] == diff) ++count;
            else {
                diff = nums[i] - nums[i-1];
                count = 1;
            }
            // cout << diff << " " << count << "\n";
            if (count >= 2) ans += count - 1;
        }
        return ans;
    }
};