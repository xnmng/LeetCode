// todo : UF solution (O(n) space)

class Solution {
private:
    bool isSimilar(string& s1, string& s2) {
        int flag{2};
        for (auto i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (flag == 0) return false;
                --flag;
            }
        }
        // cout << s1 << " similar to " << s2 << "\n";
        return true;
    }
    
    void dfs(int i, vector<vector<int>>& adjlist, vector<bool>& visited) {
        visited[i] = true;
        for (auto j : adjlist[i]) {
            if (!visited[j]) dfs(j, adjlist, visited);
        }
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {
        vector<vector<int>> adjlist(strs.size());
        for (auto i = 0; i < strs.size(); ++i) {
            for (auto j = i+1; j < strs.size(); ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                    // cout << i << " similar to " << j << "\n";
                }
            }
        }
        
        auto ans{0};
        vector<bool> visited(strs.size(), false);
        for (auto i = 0; i < strs.size(); ++i) {
            if (!visited[i]) {
                ++ans;
                dfs(i, adjlist, visited);
            }
        }
        return ans;
    }
};