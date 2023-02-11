class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> adjlist(n);
        for (auto& i : redEdges) {
            adjlist[i[0]].push_back(i[1]);
        }
        for (auto& i : blueEdges) {
            adjlist[i[0]].push_back(-1 * i[1]);
        }
        vector<int> ans(n, -1);
        auto count{0};
        queue<int> q;
        q.push(0);
        queue<int> next;
        int cur;
        unordered_set<int> visited;
        while (!q.empty()) {
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                // cout << cur << "\n";
                if (visited.find(cur) != visited.end()) continue;
                visited.insert(cur);
                if (ans[abs(cur)] == -1) ans[abs(cur)] = count;
                for (auto i : adjlist[abs(cur)]) {
                    if (i <= 0 && cur >= 0) {
                        next.push(i);
                    }
                    else if (i >= 0 && cur <= 0) {
                        next.push(i);                    
                    }
                }
            }
            ++count;
            swap(q, next);
        }
        return ans;
    }
};

// 5
// [[0,1],[1,2],[2,3],[3,4]]
// [[1,2],[2,3],[3,1]]