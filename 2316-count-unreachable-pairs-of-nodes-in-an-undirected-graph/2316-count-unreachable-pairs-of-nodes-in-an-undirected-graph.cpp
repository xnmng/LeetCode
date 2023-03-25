class Solution {
private:
    long long dfs(int i, vector<vector<int>>& adjlist, vector<int>& visited) {
        if (visited[i] == 1) return 0;
        visited[i] = 1;
        auto ans{1};
        for (auto j : adjlist[i]) {
            ans += dfs(j, adjlist, visited);
        }
        return ans;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(n);
        for (auto i : edges) {
            adjlist[i[0]].push_back(i[1]);
            adjlist[i[1]].push_back(i[0]);
        }
        long long ans{0};
        vector<int> visited(n, 0);
        long long count;
        for (auto i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                count = dfs(i, adjlist, visited);
                // cout << count << "\n";
                ans += count * (n - count);
            }
        }
        ans /= 2;
        return ans;
    }
};