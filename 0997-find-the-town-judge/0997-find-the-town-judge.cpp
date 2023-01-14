class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> truster(n+1, 0);
        vector<int> trustee(n+1, 0);
        for (auto i : trust) {
            ++truster[i[0]];
            ++trustee[i[1]];
        }
        for (auto i = 1; i <= n; ++i) {
            if (truster[i] == 0 && trustee[i] == n-1) return i;
        }
        return -1;
    }
};
// 1
// []