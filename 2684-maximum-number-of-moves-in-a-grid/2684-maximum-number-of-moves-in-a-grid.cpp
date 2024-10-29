class Solution {
public:
    // very obvious its dp
    // can also optimize to O(min(m, n)) space, although not really necessary
    // O(m * n) time, O(m * n) space solution
    //
    // note: youre travelling like this
    //     x
    //   /
    // x - x
    //   \
    //     x
    //
    // because of the traversal path, we need to traverse column by column
    // (not the typical row by row)
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                ans = max(ans, dp[i][j]);
                
                // at an invalid state
                if (j > 0 && dp[i][j] == 0) continue;
                
                if (i-1 >= 0 && 
                    j+1 < n && 
                    grid[i-1][j+1] > grid[i][j]) {
                    dp[i-1][j+1] = max(dp[i-1][j+1], 1 + dp[i][j]);
                }
                
                if (j+1 < n &&
                    grid[i][j+1] > grid[i][j]) {
                    dp[i][j+1] = max(dp[i][j+1], 1 + dp[i][j]);
                }
                
                if (i+1 < m && 
                    j+1 < n && 
                    grid[i+1][j+1] > grid[i][j]) {
                    dp[i+1][j+1] = max(dp[i+1][j+1], 1 + dp[i][j]);
                }
            }
        }
        
        // for (auto i : dp) {
        //     for (auto j : i) cout << j << " ";
        //     cout << "\n";
        // }
        
        return ans;
    }
};
// [[65,200,263,220,91,183,2,187,175,61,225,120,39],[111,242,294,31,241,90,145,25,262,214,145,71,294],[152,25,240,69,279,238,222,9,137,277,8,143,143],[189,31,86,250,20,63,188,209,75,22,127,272,110],[122,94,298,25,90,169,68,3,208,274,202,135,275],[205,20,171,90,70,272,280,138,142,151,80,122,130],[284,272,271,269,265,134,185,243,247,50,283,20,232],[266,236,265,234,249,62,98,130,122,226,285,168,204],[231,24,256,101,142,28,268,82,111,63,115,13,144],[277,277,31,144,49,132,28,138,133,29,286,45,93],[163,96,25,9,3,159,148,59,25,81,233,127,12],[127,38,31,209,300,256,15,43,74,64,73,141,200]]