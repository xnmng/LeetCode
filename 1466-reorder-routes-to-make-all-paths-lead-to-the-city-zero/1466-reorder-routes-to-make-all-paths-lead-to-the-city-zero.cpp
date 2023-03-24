class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adjlist(n); // (connected-to-node, isOriginalEdge)
        for (auto& i : connections) {
            adjlist[i[0]].emplace_back(i[1], 1);
            // cout << i[0] << " " << i[1] << " " << 1 << "\n";
            adjlist[i[1]].emplace_back(i[0], 0);
            // cout << i[1] << " " << i[0] << " " << 0 << "\n";
        }
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        int cur;
        auto ans{0};
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            visited.insert(cur);
            for (auto& [next, isOriginalEdge] : adjlist[cur]) {
                if (visited.find(next) == visited.end()) {
                    q.push(next);
                    
                    // we are performing dfs from 0;
                    // the 'correct' edge should point towards 0 
                    // not away from 0 (i.e. the edge we are using to perform bfs)
                    if (isOriginalEdge == 1) ++ans;
                }
            }
        }
        return ans;
    }
};