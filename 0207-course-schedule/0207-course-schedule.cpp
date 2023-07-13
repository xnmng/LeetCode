// https://youtu.be/EgI5nU9etnU
class Solution {
private:
    bool dfs(int index, vector<vector<int>>& adjlist, vector<bool>& visited) {
        if (adjlist[index].empty()) return true;
        if (visited[index]) return false;
        visited[index] = true;
        for (auto i = 0; i < adjlist[index].size(); ++i) {
            if (adjlist[index][i] == -1) continue;
            if (!dfs(adjlist[index][i], adjlist, visited)) return false;
            adjlist[index][i] = -1;
        }
        while (!adjlist[index].empty() && adjlist[index].back() == -1) adjlist[index].pop_back();
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        for (auto i = 0; i < prerequisites.size(); ++i) {
            adjlist[prerequisites[i][0]].emplace_back(prerequisites[i][1]);
        }
        // for (auto i : adjlist) {
        //     for (auto j : i) cout << j << " ";
        //     cout << "\n";
        // }
        for (auto i = 0; i < numCourses; ++i) {
            vector<bool> visited(numCourses, false);
            if (!dfs(i, adjlist, visited)) return false;
        }
        return true;
    }
};
// 3
// [[0,1],[0,2],[1,2]]