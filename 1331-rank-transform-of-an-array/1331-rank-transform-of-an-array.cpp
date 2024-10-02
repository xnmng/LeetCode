class Solution {
public:
    // sort using map, generate ans vector and return
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>> mp; // value to index
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            mp[arr[i]].emplace_back(i);
        }
        vector<int> ans(n);
        int rank = 1;
        for (auto [k,v] : mp) {
            for (int i : v) {
                ans[i] = rank;
            }
            ++rank;
        }
        return ans;
    }
};