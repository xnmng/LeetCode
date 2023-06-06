class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing{true};
        bool isDecreasing{true};
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i-1] > nums[i]) isIncreasing = false;
            if (nums[i-1] < nums[i]) isDecreasing = false;
            if (!isIncreasing && !isDecreasing) return false;
        }
        return isIncreasing || isDecreasing;
    }
};