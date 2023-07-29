// https://leetcode.com/problems/soup-servings/discuss/121711/C++JavaPython-When-N-greater-4800-just-return-1
class Solution {
private:
    // dp[0][b], (b > 0) = 1;
    // dp[a][0], (a > 0) = 0;
    // dp[0][0]          = 1/2;
        
    // dp[a][b] = 1/4 * dp[a-4][b] +
    //              1/4 * dp[a-3][b-1] +
    //              1/4 * dp[a-2][b-2] +
    //              1/4 * dp[a-1][b-3];
    double dfs(vector<vector<double>>& dp, int a, int b) {
        if (a <= 0 && b <= 0) return 0.5; // 1/2 evaluates to 0...
        if (a <= 0) return 1;
        if (b <= 0) return 0;
        
        if (dp[a][b] < 0) {
            dp[a][b] = (dfs(dp, a-4, b) + dfs(dp, a-3, b-1) + dfs(dp, a-2, b-2) + dfs(dp, a-1, b-3)) / 4;
        }
        return dp[a][b];
    }
public:
    double soupServings(int n) {
        if (n > 4800) return 1;
        auto servings{ceil(n / 25.0)};
        vector<vector<double>> dp(servings+1, vector<double>(servings+1, -1));
        return dfs(dp, servings, servings);
    }
};
// 