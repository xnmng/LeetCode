class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for (auto i = 0; i < nums.size(); i += 2) {
            for (auto j = 0; j < nums[i]; ++j) {
                ans.emplace_back(nums[i+1]);
            }
        }
        return ans;
    }
};