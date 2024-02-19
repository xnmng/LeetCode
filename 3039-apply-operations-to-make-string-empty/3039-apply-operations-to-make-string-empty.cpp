class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<vector<int>> v(26);
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            v[s[i] - 'a'].emplace_back(i);
            count = max(count, (int) v[s[i] - 'a'].size());
        }
        unordered_set<int> se;
        for (int i = 0; i < 26; ++i) {
            if (v[i].size() == count) se.insert(v[i].back());
        }
        string ans;
        ans.reserve(26);
        for (int i = 0; i < n; ++i) {
            if (se.find(i) != se.end()) ans += s[i];
        }
        return ans;
    }
};