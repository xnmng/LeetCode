class Solution {
public:
    // ans 2D vector will be of size m by n
    // matrix size m will be maximum frequency of some element
    // initialize m and frequency map
    // use m to initialize ans 2D vector
    // iterate across frequency map, use frequency and key to add into 2D array
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = 0;
        for (int i : nums) {
            ++mp[i];
            n = max(n, mp[i]);
        }
        vector<vector<int>> ans(n);
        for (auto& [k,v] : mp) {
            for (int i = 0; i < v; ++i) {
                ans[i].emplace_back(k);
            }
        }
        return ans;
    }
};
// [8,8,8,8,2,4,4,2,4]