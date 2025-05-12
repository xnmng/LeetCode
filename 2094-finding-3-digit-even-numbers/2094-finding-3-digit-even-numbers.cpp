class Solution {
public:
    // can just brute force 100-999, wrote dfs instead
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> s;
        unordered_map<int,int> mp;
        for (int i : digits) {
            ++mp[i];
        }
        int cur = 0;
        dfs(cur, mp, s);
        return {s.begin(), s.end()};
    }

    void dfs(int& cur, unordered_map<int,int>& mp, set<int>& s) {
        if (cur >= 100) {
            for (int i = 0; i < 9; i += 2) {
                if (mp[i] > 0) {
                    s.insert(cur + i);
                }
            }
            return;
        }

        for (int i = 0; i <= 9; ++i) {
            if (cur == 0 && i == 0) continue;
            if (mp[i] > 0) {
                cur = (cur + i) * 10;
                --mp[i];
                dfs(cur, mp, s);
                ++mp[i];
                cur = (cur / 10) - i;
            }
        }
    }
};