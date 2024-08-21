class Solution {
public:
    string triangleType(vector<int>& nums) {
        int largest = max(nums[0], max(nums[1], nums[2]));
        // to form a triangle, the sum of the 2 smaller sides must be > the largest side
        // cannot be equal (think 5,3,8)
        if (largest >= (nums[0] + nums[1] + nums[2] - largest)) return "none";
        if (nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";
        if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) return "isosceles";
        return "scalene";
    }
};