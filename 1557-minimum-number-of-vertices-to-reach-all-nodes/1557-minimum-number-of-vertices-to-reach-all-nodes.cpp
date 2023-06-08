class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        ans.reserve(n);
        vector<bool> v(n, true);
        for (auto& i : edges) {
            v[i[1]] = false;
        }
        for (auto i = 0; i < v.size(); ++i) {
            if (v[i]) ans.emplace_back(i);
        }
        return ans;
    }
};