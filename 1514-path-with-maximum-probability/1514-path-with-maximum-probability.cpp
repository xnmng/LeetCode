class Solution {
public:
    // dijkstra's
    // O(m + nlogn) for fib. heap, O(n + mlogn) for binary heap
    // where n is number of nodes, m is number of edges
    // O(n + m) space
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> v(n, 0.0);
        v[start] = 1;
        vector<int> visited(n, 0);
        vector<vector<pair<int, double>>> adjlist(n);
        for (auto i = 0; i < edges.size(); ++i) {
            adjlist[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            adjlist[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        
        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start});
        while (!pq.empty()) {
            auto [curProb, cur] = pq.top();
            pq.pop();
            if (visited[cur] == 1) continue;
            ++visited[cur];
            v[cur] = curProb;
            if (cur == end) break;
            for (auto [node, p] : adjlist[cur]) {
                if (p > 0 && visited[node] == 0) {
                    pq.push({curProb * p, node});
                }
            }
        }
        return v[end];
    }
};
// 5
// [[2,3],[1,2],[3,4],[1,3],[1,4],[0,1],[2,4],[0,4],[0,2]]
// [0.06,0.26,0.49,0.25,0.2,0.64,0.23,0.21,0.77]
// 0
// 3