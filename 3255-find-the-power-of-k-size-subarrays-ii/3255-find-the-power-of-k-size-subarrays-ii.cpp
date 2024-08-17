class Solution {
public:
    // 2 pointer approach
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n - k + 1);
        int left = 0;
        int right = 1;
        int count = 0;
        while (right + 1 != k) {
            if (nums[right-1] + 1 == nums[right]) ++count;
            ++right;
        }
        while (right < n) {
            if (nums[right] == nums[right-1] + 1) {
                ++count;
            }
            if (count != k-1) ans.emplace_back(-1);
            else ans.emplace_back(nums[right]);
            if (nums[left] + 1 == nums[left+1]) {
                --count;
            }
            ++left;
            ++right;
        }
        return ans;
    }
};
