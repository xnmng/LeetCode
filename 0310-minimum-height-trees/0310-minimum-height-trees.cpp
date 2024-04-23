class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0) return vector<int>{};
        if (n == 1) return vector<int>{0};
        vector<int> ans{};
        
        vector<unordered_set<int>> adj(n, unordered_set<int>{});
        
        for (vector<int> e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        
        queue<int> q{};
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) q.push(i);
        }
        
        while (n > 2) {
//cout << "hit \n";

            n -= q.size();
            queue<int> next{};
            while (q.size() != 0) {
                int a = q.front();
                int b = *adj[a].begin();
                //cout << a << " " << b << "\n";
                q.pop();
                adj[a].clear();
                adj[b].erase(a);
                if (adj[b].size() == 1) next.push(b);
            }
            q = next;
        }
        
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        } 
        return ans;
    }
};