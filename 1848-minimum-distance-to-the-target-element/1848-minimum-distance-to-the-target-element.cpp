// https://leetcode.com/problems/minimum-distance-to-the-target-element/discuss/1186927/C++-One-Pass-+-Optimization
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) ans = min(ans, abs(i - start));
        }
        return ans;
    }
};