class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;
        string cur(1,s[0]);
        unordered_map<string, int> mp;
        ++mp[cur];
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            if (cur[0] == s[i]) {
                ++mp[cur];
                if (mp[cur] >= 3) ans = max(ans, (int)cur.size());
                cur += s[i];
            }
            else cur = string(1,s[i]);
            ++mp[cur];
            ans = max(ans, (int)cur.size() - 2);
            if (mp[cur] >= 3) ans = max(ans, (int)cur.size());
        }
        return ans > 0 ? ans : -1;
    }
};
// "eccdnmcnkl"
// "acc"
// "cddedeedccedcedecdedcdeededdddcdddddcdeecdcddeecdc"