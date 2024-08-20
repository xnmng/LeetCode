// https://youtu.be/I-z-u0zfQtg
// https://leetcode.com/problems/stone-game-ii/solution/
class Solution {
private:
    int dfs(vector<vector<vector<int>>>& dp, vector<int>& piles,
            int isAlice, int index, int m) {
        if (index >= piles.size()) return 0;
        if (dp[isAlice][index][m] != -1) return dp[isAlice][index][m];
        
        auto val{isAlice == 1 ? 0 : INT_MAX};
        auto sum{0};
        for (auto x = 1; x <= 2 * m; ++x) {
            if (index + x - 1 == piles.size()) break;
            sum += piles[index + x - 1];
            if (isAlice == 1) {
                val = max(val, sum + dfs(dp, piles, 0, index + x, max(m, x)));
            }
            else {
                val = min(val, dfs(dp, piles, 1, index + x, max(m, x)));
            }
        }
        dp[isAlice][index][m] = val;
        return dp[isAlice][index][m];
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        if (piles.size() == 1) return piles[0];
        if (piles.size() == 2) return piles[0] + piles[1];
        
        auto n{piles.size()};
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        return dfs(dp, piles, 1, 0, 1);    
    }
};

// [1]