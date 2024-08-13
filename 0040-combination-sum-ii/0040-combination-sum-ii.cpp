class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        cur.reserve(candidates.size());
        unordered_map<int,int> mp;
        for (int i : candidates) {
            ++mp[i];
        }
        dfs(mp, mp.begin(), cur, target, ans);
        return ans;
    }
    
    void dfs(unordered_map<int,int>& mp, unordered_map<int,int>::iterator itr,
                vector<int>& cur, int target, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.emplace_back(cur);
        } else if (target > 0 && itr != mp.end()) {
            auto next = itr;
            ++next;
            auto& [k,v] = *itr;
            for (int i = 0; i <= v; ++i) {
                if (i == 0) {
                    dfs(mp, next, cur, target, ans);
                    continue;
                }
                cur.emplace_back(k);
                dfs(mp, next, cur, target - i * k, ans);
            }
            for (int i = 0; i < v; ++i) {
                cur.pop_back();            
            }
        }
    }
};