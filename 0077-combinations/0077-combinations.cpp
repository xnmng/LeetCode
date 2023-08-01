class Solution {
private:
    void dfs(int i, int j, int k, vector<int>& v, vector<vector<int>>& ans) {
        if (v.size() == k) {
            ans.emplace_back(v);
            return;
        }
        if (i > j) return;
        for (auto x = i; x <= j; ++x) {
            v.emplace_back(x);
            dfs(x+1, j, k, v, ans);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        dfs(1, n, k, v, ans);
        return ans;
    }
};