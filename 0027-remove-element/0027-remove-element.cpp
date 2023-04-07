class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto offset{0};
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) ++offset;
            else nums[i - offset] = nums[i];
        }
        // for (auto i : nums) cout << i << " ";
        // cout << "\n";
        return nums.size() - offset;
    }
};