class Solution {
public:
    // sort the array, since we want each set of 3 elements to be <= k, 
    // we check every group of 3 elements (i, i+1, i+2) for integer i 
    // if this can be satisfied
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (auto i = 0; i < nums.size(); i += 3) {
            if (nums[i+2] - nums[i] > k) return {};
            ans.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return ans;
    }
};