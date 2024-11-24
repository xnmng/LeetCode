class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int x = n / k;
        string cur = "";
        unordered_map<string, int> mp;
        for (char c : s) {
            cur += c;
            if (cur.size() == x) {
                ++mp[cur];
                cur = "";
            }
        }
        for (char c : t) {
            cur += c;
            if (cur.size() == x) {
                if (mp[cur] == 0) return false;
                --mp[cur];
                cur = "";
            }
        }
        return true;
    }
};