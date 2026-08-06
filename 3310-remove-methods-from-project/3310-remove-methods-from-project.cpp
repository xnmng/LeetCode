class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adjlist(n);        
        vector<vector<int>> revadjlist(n);        
        for (auto& i : invocations) {
            adjlist[i[0]].emplace_back(i[1]);
            revadjlist[i[1]].emplace_back(i[0]);
        }
        
        unordered_set<int> sus;
        dfs(k, adjlist, sus);
        
        vector<int> ans;
        ans.reserve(n);
        
        bool flag = false; // can we remove all sus nodes?
        for (int i = 0; i < n; i++) {
            if (!sus.count(i)) {
                for (int j : adjlist[i]) {
                    if (sus.count(j)) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) break;
        }
        
        if (ans.empty()) {
            for (int i = 0; i < n; ++i) {
                if (!sus.count(i) || flag) {
                    ans.emplace_back(i);
                }
            }
        }
    
        return ans;
    }
    
    void dfs(int k, vector<vector<int>>& adjlist, unordered_set<int>& sus) {
        sus.insert(k);
        for (int i : adjlist[k]) {
            if (!sus.count(i)) {
                dfs(i, adjlist, sus);
            }
        }
    }
};
