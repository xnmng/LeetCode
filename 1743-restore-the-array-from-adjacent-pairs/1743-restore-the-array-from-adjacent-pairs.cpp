class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& arr) {
        int n = arr.size()+1; // size of result
        vector<int> ans;
        ans.reserve(n);
        unordered_map<int,vector<int>> mp;
        for (auto& i : arr) {
            mp[i[0]].emplace_back(i[1]);
            mp[i[1]].emplace_back(i[0]);
        }
        int next;
        for (auto& [k,v] : mp) {
            if (v.size() == 1) {
                next = k;
                break;
            }
        }
        unordered_set<int> s;
        while (true) {
            ans.emplace_back(next);
            if (ans.size() == n) break;
            s.insert(next);
            for (auto i : mp[next]) {
                if (s.find(i) == s.end()) {
                    next = i;
                }
            }
        }
        return ans;
    }
};
// [[4,-2],[1,4],[-3,1]]