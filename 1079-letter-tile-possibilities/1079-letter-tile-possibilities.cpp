class Solution {
public:
    // small constraints, brute force will do
    int numTilePossibilities(string tiles) {
        unordered_set<string> s;
        string cur = "";
        vector<int> v(26, 0);
        for (char c : tiles) ++v[c - 'A'];
        int count = tiles.size();
        dfs(cur, s, v, count);
        return s.size();
    }

    void dfs(string& cur, unordered_set<string>& s, vector<int>& v, int count) {
        if (count == 0) {
            s.insert(cur);
            return;
        }
        if (s.contains(cur)) return;
        if (!cur.empty()) s.insert(cur);
        for (int i = 0; i < 26; ++i) {
            if (v[i] > 0) {
                --v[i];
                cur += 'A' + i;
                dfs(cur, s, v, count-1);
                ++v[i];
                cur.pop_back();
            }
        }
    }
};