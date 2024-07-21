class Solution {
public:
    // https://youtu.be/bbp2KWiYzHw?si=P_kPf2sk1oFZ9xvD
    vector<vector<int>> buildMatrix(int k, 
                                    vector<vector<int>>& rowConditions, 
                                    vector<vector<int>>& colConditions) {
        vector<vector<int>> rowGraph = buildGraph(k, rowConditions);
        vector<vector<int>> colGraph = buildGraph(k, colConditions);
        vector<int> rowSorted = topoSort(k, rowGraph);
        vector<int> colSorted = topoSort(k, colGraph);
        // for (auto i : rowSorted) cout << i << " ";
        // cout << "\n";
        // for (auto i : colSorted) cout << i << " ";
        // cout << "\n";
        
        vector<vector<int>> ans(k, vector<int>(k, 0));
        if (rowSorted.empty() || colSorted.empty()) return {};
        
        unordered_map<int,int> mp; // map row value to col index
        for (auto i = 0; i < k; ++i) {
            mp[colSorted[i]] = i;
        }
        
        for (int i = 0; i < k; ++i) {
            ans[i][mp[rowSorted[i]]] = rowSorted[i];
        }
        return ans;
    }
    
    // build graph using conditions
    vector<vector<int>> buildGraph(int k ,vector<vector<int>>& conditions) {
        vector<vector<int>> graph(k+1);
        for (auto& condition : conditions) {
            graph[condition[0]].emplace_back(condition[1]);
        }
        return graph;
    }
    
    // topo sort using graph, then add missing nodes at the end
    vector<int> topoSort(int k, vector<vector<int>>& graph) {
        vector<int> indeg(k+1, 0);
        for (int i = 1; i <= k; ++i) {
            for (auto node : graph[i]) {
                ++indeg[node];
            }
        }
        queue<int> q;
        vector<bool> visited(k+1, false);
        for (int i = 1; i <= k; ++i) {
            if (indeg[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        ans.reserve(k);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = true;
            ans.push_back(cur);
            for (auto node : graph[cur]) {
                --indeg[node];
                if (indeg[node] == 0) q.push(node);
            }
        }
        
        for (int i = 1; i < k; ++i) {
            // no topo sort exists; cycle present
            if (indeg[i] != 0) return {};
            if (!visited[i]) ans.emplace_back(i);
        }
        
        return ans;
    }
};