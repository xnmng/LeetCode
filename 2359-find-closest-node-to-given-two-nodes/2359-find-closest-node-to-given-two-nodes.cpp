class Solution {
private:
    void dfs(int node, vector<int>& edges, vector<int>& dist, int step) {
        dist[node] = step;
        if (edges[node] == -1) return;
        if (dist[edges[node]] == INT_MAX) dfs(edges[node], edges, dist, step + 1);
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        auto n{edges.size()};
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        dfs(node1, edges, dist1, 0);
        dfs(node2, edges, dist2, 0);
        auto ans{-1};
        auto val{INT_MAX};
        for (auto i = 0; i < n; ++i) {
            if (dist1[i] == INT_MAX || dist2[i] == INT_MAX) continue;
            if (max(dist1[i], dist2[i]) < val) {
                ans = i;
                val = max(dist1[i], dist2[i]);
            }
        };
        return ans;
    }
};

// [2,0,0]
// 2
// 0
// [4,4,8,-1,9,8,4,4,1,1]
// 5
// 6