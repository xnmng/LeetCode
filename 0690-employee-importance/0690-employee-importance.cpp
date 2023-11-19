/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> mp;
        for (auto i : employees) {
            mp[i->id] = i;
        }
        vector<int> v{id};
        int cur;
        int ans = 0;
        while (!v.empty()) {
            cur = v.back();
            v.pop_back();
            ans += mp[cur]->importance; // 1-based indexing
            for (auto i : mp[cur]->subordinates) {
                v.emplace_back(i);
            }
        }
        return ans;
    }
};