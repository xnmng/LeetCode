class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> vs(26);
        for (auto i : ideas) {
            vs[i[0] - 'a'].insert(i.substr(1));
        }
        long long ans{0};
        int common;
        for (auto i = 0; i < 26; ++i) {
            for (auto j = i+1; j < 26; ++j) {
                common = 0;
                for (auto& k : vs[i]) if (vs[j].find(k) != vs[j].end()) ++common;
                ans += 2 * (vs[i].size() - common) * (vs[j].size() - common);
                cout << ans << "\n";
            }
        }
        return ans;
    }
};