class Solution {
public:
    // dont need to check for i >= 2
    // https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/solution/
    long long largestPerimeter(vector<int>& nums) {
        long long ans = -1;
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            // check for i >= 2 here is not needed!
            // when i = 0, the condition will never be true (input elements all > 0)
            // when i = 1, the condition will never be true (we sorted the elements)
            // only when i = 2 will there be a possiblity of the condition (sum > nums[i]) returning true
            if (sum > nums[i]) {
                ans = sum + nums[i];
            }
            sum += nums[i];
        }
        return ans;
    }
};