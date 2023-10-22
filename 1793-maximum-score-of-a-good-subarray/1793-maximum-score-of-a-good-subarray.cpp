// https://leetcode.com/problems/maximum-score-of-a-good-subarray/solution/
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k;
        int right = k;
        int smallest = nums[k];
        int ans = nums[k];
        while (left-1 >= 0 || right+1 < n) {
            if ((left-1 >= 0 ? nums[left-1] : 0) > (right+1 < n ? nums[right+1] : 0)) {
                --left;
                smallest = min(smallest, nums[left]);
            } else {
                ++right;
                smallest = min(smallest, nums[right]);
            }
            // cout << left << " " << right << " " << smallest << "\n";
            ans = max(ans, (right - left + 1) * smallest);
        }
        return ans;
    }
};