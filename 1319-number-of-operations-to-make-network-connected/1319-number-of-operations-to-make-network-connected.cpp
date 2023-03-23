class Solution {
private:
    void dfs(int i, vector<vector<int>>& adjlist, unordered_set<int>& visited) {
        visited.insert(i);
        for (auto j : adjlist[i]) {
            if (visited.find(j) == visited.end()) {
                dfs(j, adjlist, visited);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        auto count{-1};
        unordered_set<int> visited;
        vector<vector<int>> adjlist(n, vector<int>());
        for (auto& i : connections) {
            adjlist[i[0]].push_back(i[1]);
            adjlist[i[1]].push_back(i[0]);
        }
        for (auto i = 0; i < n; ++i) {
            if (visited.find(i) == visited.end()) {
                ++count;
                dfs(i, adjlist, visited);
            }
        }
        return count;
    }
};