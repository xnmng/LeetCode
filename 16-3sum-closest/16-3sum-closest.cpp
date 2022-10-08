// https://leetcode.com/problems/3sum-closest/discuss/7883/C++-solution-O(n2)-using-sort

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto ans{nums[0] + nums[1] + nums[2]};
        auto last{static_cast<int>(nums.size()-1)};
        for (auto i = 0; i < nums.size()-2; ++i) {
            if (ans == target) return target;
            auto left{i+1};
            auto right{last};
            while (left < right) {
                if (abs(ans - target) > abs(target - nums[i] - nums[left] - nums[right])) {
                    ans = nums[i] + nums[left] + nums[right];
                }
                if (nums[i] + nums[left] + nums[right] - target > 0) {
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return ans;
    }
};