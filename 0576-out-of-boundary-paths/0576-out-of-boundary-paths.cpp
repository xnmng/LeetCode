class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        int modulo = 1e9 + 7;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;
        vector<int> xdir{0,0,1,-1};
        vector<int> ydir{1,-1,0,0};
        while (maxMove > 0) {
            vector<vector<int>> next(m, vector<int>(n, 0));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        int newX = i + xdir[k];
                        int newY = j + ydir[k];
                        if (newX >= 0 && newX < m 
                            && newY >= 0 && newY < n) {
                            next[newX][newY] = (next[newX][newY] + dp[i][j]) % modulo;
                        } else {
                            ans = (ans + dp[i][j]) % modulo;
                        }
                    }
                }
            }
            --maxMove;
            swap(next, dp);
        }
        return ans;
    }
};