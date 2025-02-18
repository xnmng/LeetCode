class Solution {
public:
    // each index is 1 to 9
    // if it is i, it cannot be 9 (cannot go higher than 9)
    // if it is d, it cannot be 1 (cannot go lower than 1)
    // small size constraints, do dfs
    string smallestNumber(string pattern) {
        string ans = "";
        string cur = "";
        vector<bool> v(10, false);
        dfs(cur, pattern, ans, -1, v);
        return ans;
    }

    void dfs(string& cur, string& pattern, string& ans, int index, vector<bool>& v) {
        if (cur.size() > pattern.size()) {
            if (cur < ans || ans.empty()) ans = cur;
            return;
        }
        else if (index < 0) {
            for (int i = 1; i <= 9; ++i) {
                if (v[i]) continue;
                v[i] = true;
                cur += '0' + i;
                dfs(cur, pattern, ans, index + 1, v);
                cur.pop_back();
                v[i] = false;
            }
        }
        else {
            if (pattern[index] == 'I') {
                for (int i = cur.back() - '0' + 1; i <= 9; ++i) {
                    if (v[i]) continue;
                    v[i] = true;
                    cur += '0' + i;
                    dfs(cur, pattern, ans, index + 1, v);
                    cur.pop_back();
                    v[i] = false;
                }
            }
            else if (pattern[index] == 'D') {
                for (int i = cur.back() - '0' - 1; i > 0; --i) {
                    if (v[i]) continue;
                    v[i] = true;
                    cur += '0' + i;
                    dfs(cur, pattern, ans, index + 1, v);
                    cur.pop_back();
                    v[i] = false;
                }
            }
        }
    }
};
// "DDDDDDDD"