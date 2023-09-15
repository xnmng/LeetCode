// https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/843940/C++-MST:-Kruskal-+-Prim's-+-Complete-Graph
// kruskal's algo (add min edges until MST is formed)
class Solution {
private:
    int findParent(vector<int>& parent, int index) {
        // cout << index << " " << parent[index] << "\n";
        if (parent[index] == -1) {
            parent[index] = index;
            return index;
        }
        if (parent[index] == index) return index; // dont forget this! else infinite loop!
        parent[index] = findParent(parent, parent[index]);
        return parent[index];
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 0;
        
        auto comp = [](pair<int, pair<int,int>> a, pair<int, pair<int,int>> b) {
            return a.first > b.first;
        };
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, decltype(comp)> pq(comp);
        for (auto i = 0; i < points.size(); ++i) {
            for (auto j = i+1; j < points.size(); ++j) {
                pq.emplace(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), 
                           pair<int,int>{i, j});
            }
        }
        auto ans{0};
        auto count{0};
        vector<int> parent(points.size(), -1);
        while (count != points.size()-1) { // todo stopping condition
            auto cur{pq.top()};
            pq.pop();
            // same parent -> we are on a redundant edge; ignore
            if (findParent(parent, cur.second.first) == findParent(parent, cur.second.second)) continue;
            ans += cur.first;
            ++count;
            // cout << cur.first << " " << cur.second.first << " " << cur.second.second << "\n";
            parent[findParent(parent, cur.second.first)] = findParent(parent, cur.second.second);
            // break;
        }
        return ans;
    }
};

// edge case!
// [[0,0]]

// n components -> use union find and count for stopping condition!
// otherwise will get n components that are not connected
// [[2,-3],[-17,-8],[13,8],[-17,-15]]