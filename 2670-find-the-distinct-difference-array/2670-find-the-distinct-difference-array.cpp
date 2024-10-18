class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(nums[i]);
            ans[i] += s.size();
        }
        s.clear();
        for (int i = n-1; i >= 0; --i) {
            ans[i] -= s.size();
            s.insert(nums[i]);
        }
        return ans;
    }
};