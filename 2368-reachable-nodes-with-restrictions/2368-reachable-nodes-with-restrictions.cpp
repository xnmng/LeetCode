class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> uset(restricted.begin(), restricted.end());
        unordered_set<int> visited;
        vector<vector<int>> adjlist(n);
        for (auto& i : edges) {
            adjlist[i[0]].emplace_back(i[1]);
            adjlist[i[1]].emplace_back(i[0]);
        }
        dfs(0, adjlist, visited, uset);
        return visited.size();
    }
    
    void dfs(int cur, vector<vector<int>>& adjlist, 
             unordered_set<int>& visited, unordered_set<int>& restricted) {
        if (restricted.find(cur) != restricted.end() 
            || visited.find(cur) != restricted.end()) return;
        visited.insert(cur);
        for (auto& i : adjlist[cur]) {
            dfs(i, adjlist, visited, restricted);
        }
    }
};