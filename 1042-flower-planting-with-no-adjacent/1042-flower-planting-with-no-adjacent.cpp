class Solution {
private:
    void dfs(int i, vector<int>& ans, vector<vector<int>>& adjlist) {
        // cout << i << "\n";
        vector<bool> v(4, false);
        if (ans[i] == 0) {
            for (auto j : adjlist[i]) {
                if (ans[j] > 0) {
                    // cout << ans[j] - 1 << "\n";
                    v[ans[j]-1] = true;
                }
            }
            for (auto j = 0; j < 4; ++j) {
                if (!v[j]) {
                    // cout << "label " << i << " with " << j+1 << "\n";
                    ans[i] = j+1;
                    break;
                }
            }
            for (auto j : adjlist[i]) {
                dfs(j, ans, adjlist);
            }
        }
    }
public:
    // 1-based indexing
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adjlist(n);
        for (auto& i : paths) {
            adjlist[i[0]-1].emplace_back(i[1]-1);
            adjlist[i[1]-1].emplace_back(i[0]-1);
        }
        vector<int> ans(n, 0); // use 0 as sentinel value
        for (auto i = 0; i < n; ++i) {
            dfs(i, ans, adjlist);
        }
        return ans;
    }
};