// The necessary and sufficient condition for 3 lengths to form a triangle of non-zero area is a + b > c.
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        // for (auto i : nums) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        for (auto i = 2; i < nums.size(); ++i) {
            if (nums[i] + nums[i-1] > nums[i-2]) return nums[i] + nums[i-1] + nums[i-2];
        }
        return 0;
    }
};