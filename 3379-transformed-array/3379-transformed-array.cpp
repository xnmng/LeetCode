class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n);
        int index;
        for (int i  = 0; i < n; ++i) {
            index = i + nums[i];
            while (index < 0) index += n;
            ans.emplace_back(nums[index % n]);
        }
        return ans;
    }
};