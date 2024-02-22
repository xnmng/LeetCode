class Solution {
public:
    // check if there exists 1 person who everyone trusts and trusts no one
    // maintain 2 counts for each person: who they trust and who trusts them
    // check that if there is anyone who has trust[i] == 0 and trusted[i] == n-1
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