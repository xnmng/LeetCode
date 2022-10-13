class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        vector<vector<int>> adjList(n);
        for (auto i : edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
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
// 10
// [[2,9],[7,8],[5,9],[7,2],[3,8],[2,8],[1,6],[3,0],[7,0],[8,5]]
// 1
// 0
// https://leetcode.com/submissions/detail/821341850/