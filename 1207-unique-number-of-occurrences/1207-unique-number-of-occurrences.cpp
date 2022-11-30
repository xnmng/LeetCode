class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for (auto i : arr) {
            ++mp[i];
        }
        unordered_set<int> s;
        for (auto& [k,v] : mp) {
            if (!s.insert(v).second) return false;
        }
        return true;
    }
};