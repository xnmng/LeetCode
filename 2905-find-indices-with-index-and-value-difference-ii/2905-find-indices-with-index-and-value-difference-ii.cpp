class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        int maxIndex = 0; // index of largest element value we encountered so far
        int minIndex = 0; // index of smallest element value we encountered so far
        for (auto i = indexDifference; i < n; ++i) {
            if (nums[i - indexDifference] > nums[maxIndex]) maxIndex = i - indexDifference;
            if (nums[i - indexDifference] < nums[minIndex]) minIndex = i - indexDifference;
            if (abs(nums[maxIndex] - nums[i]) >= valueDifference) return {maxIndex, i};
            if (abs(nums[minIndex] - nums[i]) >= valueDifference) return {minIndex, i};
        }
        return {-1, -1};
    }
};
// [7,6,3,5,9,5]
// 2
// 6