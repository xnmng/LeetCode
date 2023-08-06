// https://leetcode.com/problems/number-of-music-playlists/solution/
class Solution {
private:
    // dp[i][j] := number of music playlists that are 
    // of length i using j songs
    long dfs(int i, int j, int k, vector<vector<long>>& dp) {
        if (dp[i][j] == -1) {
            if (i == 0 || j == 0) {
                /* 
                (note: here we already handled 
                i == 0 and j == 0)
                
                if i == 0 and j > 0, not possible to make
                any playlists of length 0 AND have each 
                unique song j in the playlist
                
                (the case where j > i, dp[i][j] = 0 
                is covered by the recursion)
                
                if i > 0 and j == 0, not possible to make
                any playlist of length i without any songs
                j to choose from
                */
                dp[i][j] = 0;
            } else {
                auto modulo{static_cast<long>(1e9+7)};
                int res{0l};
                /*
                we can add a new song 
                (increase length by 1, increase songs by 1)
                (implies that we go from a valid previous state 
                to this state)
                how many options do we have?

                we can add a new song to the previous state (dp[i-1][j-1])
                how many songs can we choose from?
                total of n songs, j-1 have been used
                thus we can choose from n - (j-1) = n - j + 1
                */
                auto n = dp[0].size() - 1;
                res = (res + dfs(i-1, j-1, k, dp) * (n - j + 1)) 
                    % modulo;
                
                /*
                we can also repeat a previously played song,
                (increase length by 1, keep songs the same)
                this can only be done when current number of songs 
                is more than k
                i.e. (j > k)
                
                how many songs can we select from?
                if there needs to be k songs, we can only choose 
                from songs outside of these k
                we have a total of j songs. 
                thus we have (j - k) songs to choose from
                */
                if (j > k) res = (res + dfs(i-1, j, k, dp) * (j - k))
                    % modulo;
                dp[i][j] = res;
            }
        }
        return dp[i][j];
    }
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long>> dp(goal+1, vector<long>(n+1, -1));
        // 1 way of making music playlists of length 0 using 0 songs; 
        // i.e. empty playlist
        dp[0][0] = 1;
        return dfs(goal, n, k, dp);
    }
};
// 16
// 19
// 5