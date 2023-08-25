// https://leetcode.com/problems/interleaving-string/discuss/1247165/C++-Memoizn(3-variables)-greater-Memoizn(without-3rd-var)-greater-DP-(m*n)-greater-DP(n)
class Solution {
private:
    bool dfs(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        if (dp[i][j] == -1) {
            if (i < s1.size() && s3[i+j] == s1[i] && dfs(i+1, j, s1, s2, s3, dp)) {
                    dp[i][j] = 1;
            }
            else if (j < s2.size() && s3[i+j] == s2[j] && dfs(i, j+1, s1, s2, s3, dp)) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = 0;
            }
        }
        return dp[i][j] == 1;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        int m(s1.size());
        int n(s2.size());
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        dp[m][n] = 1;
        return dfs(0, 0, s1, s2, s3, dp);
    }
};