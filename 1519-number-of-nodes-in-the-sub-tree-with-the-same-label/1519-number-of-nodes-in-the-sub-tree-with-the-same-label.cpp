class Solution {
private:
    vector<int> dfs(int cur, vector<vector<int>>& adjList, string& labels, vector<int>& ans) {
        vector<int> a(26,0);
        vector<int> res;
        ++ans[cur];
        for (auto& i : adjList[cur]) {
            if (ans[i] == 0) {
                res = dfs(i, adjList, labels, ans);
                for (auto i = 0; i < 26; ++i) {
                    a[i] += res[i];
                }
            }
        }
        ++a[labels[cur] - 'a'];
        ans[cur] = a[labels[cur] - 'a'];
        return a;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n);
        vector<vector<int>> adjList(n);
        for (auto i : edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        dfs(0, adjList, labels, ans);
        return ans;
    }
};