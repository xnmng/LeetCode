class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int len = queries.size();
        vector<int> ans;
        ans.reserve(len);
        vector<vector<int>> adjlist(n);
        for (int i = 0; i < n; ++i) adjlist[i].emplace_back(i+1);
        for (auto& query : queries) {
            adjlist[query[0]].emplace_back(query[1]);
            ans.emplace_back(bfs(adjlist));
        }
        return ans;
    }
    
    int bfs(vector<vector<int>>& adjlist) {
        queue<int> q;
        queue<int> next;
        int ans = 0;
        q.push(0);
        int n = adjlist.size();
        vector<bool> visited(n, false);
        while (!q.empty()) {
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                visited[cur] = true;
                if (cur == n-1) return ans;
                for (auto i : adjlist[cur]) {
                    if (!visited[i]) next.push(i);
                }
            }
            swap(q, next);
            ++ans;
        }
        
        // should never happen
        return -1;
    }
};