class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        vector<vector<int>> adjList(n);
        for (auto i : edges) {
            adjList[min(i[0], i[1])].push_back(max(i[0], i[1]));
            adjList[max(i[0], i[1])].push_back(min(i[0], i[1]));
        }
        vector<bool> v(n, false);
        queue<int> q;
        q.push(source);
        int cur;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (v[cur]) continue;
            if (cur == destination) return true;
            // cout << cur << "\n";
            v[cur] = true;
            for (auto i : adjList[cur]) {
                q.push(i);
            }
        }
        return false;
    }
};

// the edges are BIDIRECTIONAL! need 2 entries in adj list!
// 10
// [[4,3],[1,4],[4,8],[1,7],[6,4],[4,2],[7,4],[4,0],[0,9],[5,4]]
// 5
// 9