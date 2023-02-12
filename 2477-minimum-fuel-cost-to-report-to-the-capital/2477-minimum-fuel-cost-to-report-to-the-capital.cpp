class Solution {
private:
    int dfs(int cur, vector<vector<int>>& adjlist, int& seats, long long& ans, unordered_set<int>& visited) {
        visited.insert(cur);
        auto sum{1};
        for (auto i : adjlist[cur]) {
            if (visited.find(i) != visited.end()) continue;            
            sum += dfs(i, adjlist, seats, ans, visited);
        }
        ans += ceil(1.0 * sum / seats);
        return sum;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> adjlist(roads.size()+1);
        for (auto& i : roads) {
            adjlist[i[0]].push_back(i[1]);
            adjlist[i[1]].push_back(i[0]);
        }
        auto ans{0ll};
        unordered_set<int> visited;
        visited.insert(0);
        
        for (auto i : adjlist[0]) {
            dfs(i, adjlist, seats, ans, visited);
        }
        return ans;
    }
};

// [[0,1],[1,2],[1,3],[4,2],[5,3],[6,3],[6,7],[8,6],[9,0],[5,10],[11,9],[12,5],[5,13],[8,14],[11,15],[8,16],[17,0],[18,7]]
// 13