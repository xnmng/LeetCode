// https://youtu.be/1XkMFNvkouo?si=bcxNHUzOOZGGcx32
class Solution {
public:
    /*
    can start from anywhere in the graph
    n<12, use bitmask to track which nodes have been visited
    need to avoid infinite loops -> (if same bitmask and index, dont process)
    
    */
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = (1 << n) - 1;
        vector<vector<bool>> v(n, vector<bool>(target, false)); // <index, bitmask>
        queue<pair<int,int>> q;
        for (auto i = 0; i < n; ++i) {
            q.emplace(i, 1 << i);
        }
        int count = 0;
        while (!q.empty()) {
            queue<pair<int,int>> next;
            while (!q.empty()) {
                auto [index, bitmask] = q.front();
                q.pop();
                if (!v[index][bitmask]) {
                    v[index][bitmask] = true;
                    bitmask |= (1 << index);
                    if (bitmask == target) {
                        next = queue<pair<int,int>>();
                        break;
                    }
                    for (auto i : graph[index]) {
                        next.emplace(i, bitmask);
                    }
                }
            }
            swap(next, q);
            if (!q.empty()) ++count;
        }
        return count;
    }
};