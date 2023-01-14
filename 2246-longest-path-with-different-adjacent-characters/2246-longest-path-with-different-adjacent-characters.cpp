class Solution {
private:
    int dfs(int i, vector<vector<int>>& adjList, vector<bool>& visited, int& ans) {
        // cout << i << "\n";
        visited[i] = true;
        auto max1{0};
        auto max2{0};
        auto cur{0};
        for (auto& j : adjList[i]) {
            if (!visited[j]) {
                cur = dfs(j, adjList, visited, ans);
            }
            if (cur > max1) {
                swap(max1, max2);
                swap(cur, max1);
            } else if (cur > max2) {
                swap(cur, max2);
            }
            // cout << max1 << " " << max2 << "\n";
        }
        ans = max(ans, max1 + max2 + 1);
        return 1 + max(max1, max2);
    }
public:
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> adjList(parent.size());
        int j;
        for (auto i = 0; i < parent.size(); ++i) {
            j = parent[i];
            if (i != 0 && s[i] != s[j]) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
                // cout << i << " " << j << "\n";
            }
        }
        auto ans{0};
        vector<bool> visited(parent.size(), false);
        for (auto i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                dfs(i, adjList, visited, ans);
            }
        }
        return ans;
    }
};
// [-1,0,1,2,3,4]
// "zzabab"