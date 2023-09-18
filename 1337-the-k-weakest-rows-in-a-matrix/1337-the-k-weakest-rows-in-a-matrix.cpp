class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v(mat.size()); // <count, index>
        for (auto i = 0; i < mat.size(); ++i) {
            v[i].second = i;
            for (auto j : mat[i]) {
                v[i].first += j;
            }
        }
        sort(v.begin(), v.end());
        vector<int> ans(k);
        for (auto i = 0; i < k; ++i) {
            ans[i] = v[i].second;
        }
        return ans;
    }
};