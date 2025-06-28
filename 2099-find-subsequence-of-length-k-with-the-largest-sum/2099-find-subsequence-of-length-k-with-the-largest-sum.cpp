class Solution {
public:
    // since subsequence must have order preserved
    // store index with element
    // sort to obtain top k elements
    // sort by index top k elements
    // extract values as ans
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> v;
        v.reserve(n);
        for (int i = 0; i < n; ++i) {
            v.emplace_back(i, nums[i]);
        }
        sort(v.begin(), v.end(), 
            [&](auto i, auto j) { return i.second > j.second; });
        sort(v.begin(), v.begin() + k);

        vector<int> ans;
        ans.reserve(k);
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(v[i].second);
        }
        return ans;
    }
};