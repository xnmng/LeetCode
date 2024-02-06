class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        string s;
        for (auto& i : strs) {
            s = i;
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        for (auto& [k,v] : mp) {
            ans.push_back(v);
        }
        return ans;
    }
};