// https://leetcode.com/problems/sum-of-distances-in-tree/solutions/1308366/c-solution-using-dfs-with-explanation-o-n-time-complexity/?orderBy=most_votes
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n);
        vector<vector<int>> adjList(n);
        for (auto i : edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        vector<int> count(n);
        dfs(0, adjList, count, ans);
        // cout << ans[0] << "\n";
        // for (auto i : count) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        dfs2(0, adjList, count, ans);
        return ans;
    }
private:
    void dfs(int cur, vector<vector<int>>& adjList, vector<int>& count, vector<int>& ans, int parent = -1) {
        for (auto i : adjList[cur]) {
            if (i == parent) continue;
            dfs(i, adjList, count, ans, cur);
            count[cur] += count[i];
            ans[cur] += ans[i] + count[i];
        }
        ++count[cur];
    }

    void dfs2(int cur, vector<vector<int>>& adjList, vector<int>& count, vector<int>& ans, int parent = -1) {
        for (auto i : adjList[cur]) {
            if (i == parent) continue;
            // ans[i] = ans[cur] - count[i] + adjList.size() - count[i];
            ans[i] = ans[cur] + adjList.size() - (2 * count[i]); // simplified formula
            dfs2(i, adjList, count, ans, cur);
        }
    }
};