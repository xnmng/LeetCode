class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        auto ans{0};
        vector<vector<int>> adjlist(n);
        for (auto i = 0; i < manager.size(); ++i) {
            if (manager[i] == -1) continue;
            adjlist[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.emplace(headID, 0);
        while (!q.empty()) {
            auto [cur, time] = q.front();
            q.pop();
            ans = max(time, ans);
            for (auto i : adjlist[cur]) {
                q.emplace(i, time + informTime[cur]);
            }
        }
        return ans;
    }
};