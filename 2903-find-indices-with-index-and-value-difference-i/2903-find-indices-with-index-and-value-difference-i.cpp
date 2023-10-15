class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        for (auto i = 0; i < n - indexDifference; ++i) {
            // cout << i << " " << n - indexDifference << "\n";
            for (auto j = i + indexDifference; j < nums.size(); ++j) {
                // cout << i << " " << j << "\n";
                if (abs(nums[i] - nums[j]) >= valueDifference) return {i, j};
            }
        }
        return {-1, -1};
    }
};
// [0]
// 100
// 50