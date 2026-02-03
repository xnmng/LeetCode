class Solution {
public:
    // check for 3 monotonic sequences using index
    // if < 3 sequences or no matching monotonic sequence, return false
    // at the end of 3rd index must reach the end of nums
    // O(n) time, O(1) space
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        while (i + 1 < n && nums[i] < nums[i + 1]) ++i;
        if (i == 0 || i == n - 1) return false;

        int j = i;
        while (j + 1 < n && nums[j] > nums[j + 1]) ++j;
        if (j == i || j == n - 1) return false;

        i = j; // reuse i variable
        while (i + 1 < n && nums[i] < nums[i + 1]) ++i;
        return i == n - 1;
    }
};