class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> v(26, false);
        for (char c : allowed) v[c - 'a'] = true;
        int ans = 0;
        bool flag;
        for (auto& i : words) {
            flag = true;
            for (char c : i) {
                if (!v[c - 'a']) {
                    flag = false;
                    break;
                }
            }
            ans += flag ? 1 : 0;
        }
        return ans;
    }
};