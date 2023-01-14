class Solution {
private:
    void dfs(vector<vector<int>>& adjList, unordered_set<int>& s, int cur) {
        // cout << cur << "\n";
        s.insert(cur);
        for (auto i = 0; i < adjList.size(); ++i) {
            if (adjList[cur][i] == 1 && s.find(i) == s.end()) dfs(adjList, s, i);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_set<int> s;
        auto ans{0};
        for (auto i = 0; i < isConnected.size(); ++i) {
            if (s.find(i) == s.end()) {
                // cout << "inc\n";
                ++ans;
                dfs(isConnected, s, i);
            }
        }
        return ans;
    }
};

// go through entire row! not just 1 "triangle" of the adjacency list!
// [[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]