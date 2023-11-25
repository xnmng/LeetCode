// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/solution/
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // sum = leftSum + nums[i] + rightSum (where leftSum and rightSum are relative to nums[i])
        // utilize the sorted property of nums to solve the problem:
        //      ans[i] = left + right, where
        //
        //      left := nums[i] * (number of elements < nums[i]) 
        //              - leftSum (sum of elements smaller than i)
        //      right := rightSum (sum of elements greater than i)
        //              - nums[i] * (number of elements > nums[i])        
        int sum = 0;
        int leftSum = 0;
        int rightSum = 0;
        int n = nums.size();
        for (auto i : nums) sum += i;
        vector<int> ans;
        for (auto i = 0; i < n; ++i) {
            rightSum = sum - leftSum - nums[i];
            ans.emplace_back(i * nums[i] - leftSum + rightSum - (n - i - 1) * nums[i]);
            leftSum += nums[i];
        }
        return ans;
    }
};
/*
i[0] = (a[0] - a[0]) + (a[1] - a[0]) + (a[2] - a[0])
*/