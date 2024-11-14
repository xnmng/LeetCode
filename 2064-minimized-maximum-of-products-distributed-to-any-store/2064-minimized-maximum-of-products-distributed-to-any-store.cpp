class Solution {
public:
    // binary search for the maximum
    int minimizedMaximum(int n, vector<int>& nums) {
        int left = 0;
        int right = INT_MAX;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (helper(n, nums, mid)) {
                right = mid;
            } 
            else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool helper(int n, vector<int> nums, int limit) {
        if (limit == 0) return false;
        int index = 0;
        int k;
        for (int i = 0; i < nums.size(); ++i) {
            k = nums[i] / limit;
            if (k * limit != nums[i]) ++k;
            index += k;
        }
        return index <= n;
    }
};
// 1
// [1]