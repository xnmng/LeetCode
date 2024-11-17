class Solution {
public:
    // brute force (TODO: might have more efficient solution, but this suffices for contest)
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0 && simulate(nums, i, 1)) ++ans; 
            if (nums[i] == 0 && simulate(nums, i, -1)) ++ans; 
        }
        return ans;
    }

    bool simulate(vector<int> nums, int i, int dir) {
        int n = nums.size();
        while (i >= 0 && i < n) {
            if (nums[i] == 0) i += dir;
            else {
                --nums[i];
                dir = -dir;
                i += dir;
            }
        }
        for (int j : nums) if (j != 0) return false;
        return true;
    }
};