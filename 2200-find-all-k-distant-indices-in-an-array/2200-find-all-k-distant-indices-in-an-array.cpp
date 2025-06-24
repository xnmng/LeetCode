class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> v(n, false);
        vector<int> ans;
        ans.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                for (int j = -k; j <= k; ++j) {
                    if (i + j >= 0 && i + j < n) v[i + j] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (v[i]) ans.emplace_back(i);
        }
        return ans;
    }
};