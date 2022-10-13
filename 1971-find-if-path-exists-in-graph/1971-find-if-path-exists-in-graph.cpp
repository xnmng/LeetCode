class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        for (auto i : edges) {
            adjList[min(i[0], i[1])].push_back(max(i[0], i[1]));
            adjList[max(i[0], i[1])].push_back(min(i[0], i[1]));
        }
        unordered_set<int> s;
        queue<int> q;
        q.push(source);
        int cur;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (s.find(cur) != s.end()) continue;
            // cout << cur << "\n";
            s.insert(cur);
            for (auto i : adjList[cur]) {
                q.push(i);
            }
        }
        return s.find(destination) != s.end();
    }
};

// the edges are BIDIRECTIONAL! need 2 entries in adj list!
// 10
// [[4,3],[1,4],[4,8],[1,7],[6,4],[4,2],[7,4],[4,0],[0,9],[5,4]]
// 5
// 9