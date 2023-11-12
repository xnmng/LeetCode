// https://leetcode.com/problems/bus-routes/solution/
class Solution {
    bool helper(unordered_set<int>& i, unordered_set<int>& j) {
        for (auto k : i) {
            if (j.find(k) != j.end()) return true;
        }
        return false;
    }
public:
    // nodes are buses
    // edges are between buses that share a common bus stop
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        vector<int> cur;
        vector<int> next;
        vector<bool> target_buses(n, false);
        vector<unordered_set<int>> v(n); // bus number -> bus stops it visits
        // initialize vector of maps, use the same time to initialize source nodes and target set
        for (auto i = 0; i < n; ++i) {
            for (auto j : routes[i]) {
                v[i].insert(j);
                if (j == source) cur.emplace_back(i);
                if (j == target) target_buses[i] = true;
            }
        }
        // build adj list between buses
        vector<vector<int>> adjlist(n);
        for (auto i = 0; i < n; ++i) {
            for (auto j = i+1; j < n; ++j) {
                if (helper(v[i], v[j])) {
                    adjlist[i].emplace_back(j);
                    adjlist[j].emplace_back(i);
                }
            }
        }
        int count = 1;
        vector<bool> visited(n, false);
        int node;
        while (!cur.empty()) {
            while (!cur.empty()) {
                node = cur.back();
                cur.pop_back();
                if (target_buses[node]) return count;
                if (!visited[node]) {
                    visited[node] = true;
                    for (auto i : adjlist[node]) next.emplace_back(i);
                }
            }
            swap(cur, next);
            ++count;
        }
        return -1;
    }
};