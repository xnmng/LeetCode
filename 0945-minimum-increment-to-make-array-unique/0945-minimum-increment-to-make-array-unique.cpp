// https://leetcode.com/problems/minimum-increment-to-make-array-unique/solution/
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto ans{0};
        auto prev{nums[0]};
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] <= prev) {
                ans += (prev + 1) - nums[i];
                ++prev;
            } else {
                prev = nums[i];                
            }
        }
        return ans;
    }
};