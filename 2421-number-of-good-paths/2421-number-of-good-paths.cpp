class Solution {
private:
    int join(int x, int y, vector<int>& v, vector<int>& r) {
        if (x > y) return join(y, x, v, r);
        auto xp{find(x, v)};
        auto yp{find(y, v)};
        if (xp == yp) return xp;
        v[yp] = xp;
        // cout << "join " << yp << " to " << xp << "\n";
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
        vector<int> r(vals.size());                 // rank DS
        map<int, vector<int>> mp;                   // nodes we need to process for each unique value
        
        for (auto i = 0; i < vals.size(); ++i) {
            mp[vals[i]].push_back(i);
        }
        auto ans{0};
        int val;
        for (auto& [k, ls] : mp) {
            unordered_map<int,int> mp2;
            // cout << "process: ";
            for (auto j : ls) {
                // cout << j << " ";
                for (auto k : adjList[j]) {
                    join(j, k, v, r);
                }
            }
            // cout << "\n";
            for (auto j : ls) {
                val = find(j, v);
                // cout << "parent of " << j << " is " << val << "\n";
                ++mp2[val];
                ans += mp2[val];
                // cout << "node: " << j << " -> " << mp2[val] << "\n";
            }
        }
            
        // for (auto i : v) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        // for (auto i = 0; i < v.size(); ++i) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        return ans;
    }
};

// O(nlogn) time
// O(n) space