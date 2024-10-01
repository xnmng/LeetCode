class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> v;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == x) v.emplace_back(i);
        }
        vector<int> ans;
        int m = queries.size();
        ans.reserve(m);
        for (int i = 0; i < m; ++i) {
            if (v.size() < queries[i]) {
                ans.emplace_back(-1);
            }
            else ans.emplace_back(v[queries[i] - 1]);
        }
        return ans;
    }
};