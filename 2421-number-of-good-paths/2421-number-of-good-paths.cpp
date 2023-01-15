class Solution {
private:
    int join(int x, int y, vector<int>& v) {
        if (x > y) return join(y, x, v);
        auto xp{find(x, v)};
        auto yp{find(y, v)};
        if (xp == yp) return xp;
        v[yp] = xp;
        return yp;
    }
    
    int find(int x, vector<int>& v) {
        if (v[x] == -1) return x;
        v[x] = find(v[x], v);
        return v[x]; 
    }
    
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(vals.size());   // adj. list
        for (auto& i : edges) {
            if (vals[i[0]] >= vals[i[1]]) adjList[i[0]].push_back(i[1]);
            if (vals[i[1]] >= vals[i[0]]) adjList[i[1]].push_back(i[0]);
        }
        
        vector<int> v(vals.size(), -1);             // union-find DS
        map<int, vector<int>> mp;                   // nodes we need to process for each unique value
        
        for (auto i = 0; i < vals.size(); ++i) {
            mp[vals[i]].push_back(i);
        }
        auto ans{0};
        int val;
        for (auto& [k, ls] : mp) {
            unordered_map<int,int> mp2;
            for (auto j : ls) {
                for (auto k : adjList[j]) {
                    join(j, k, v);
                }
            }
            for (auto j : ls) {
                val = find(j, v);
                ++mp2[val];
                ans += mp2[val];
            }
        }
        return ans;
    }
};