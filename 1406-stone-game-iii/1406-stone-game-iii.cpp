// https://youtu.be/HsLG5QW9CFQ
// https://leetcode.com/problems/stone-game-iii/solution/

// bottom up space optimized solution (O(n) time, O(1) space)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(4, 0);
        int n{static_cast<int>(stoneValue.size())};
        auto val{INT_MIN};
        for (auto i = n-1; i >= 0; --i) {
            val = max(val, stoneValue[i] - dp[(i+1) % 4]);
            if (i+1 < n) 
                val = max(val, stoneValue[i+1] + stoneValue[i] - dp[(i+2) % 4]);
            if (i+2 < n) 
                val = max(val, stoneValue[i+2] + stoneValue[i+1] + stoneValue[i] - dp[(i+3) % 4]);
            
            dp[i % 4] = val;
            val = INT_MIN;
        }
        
        if (dp.front() > 0) return "Alice";
        if (dp.front() < 0) return "Bob";
        return "Tie";
    }
};

// top down solution (O(n) time, O(n) space)
// class Solution {
// private:
//     int dfs(vector<int>& stoneValue, vector<int>& dp, int index, bool isAlice) {
//         if (index == stoneValue.size()) return 0;
//         if (dp[index] != INT_MIN) return dp[index];
//         auto val{INT_MIN};
//         auto sum{0};
//         for (auto i = 0; i < 3; ++i) {
//             if (index + i == stoneValue.size()) break;
//             sum += stoneValue[index + i];
//             val = max(val, sum - dfs(stoneValue, dp, index+i+1, !isAlice));                
//         }
//         dp[index] = val;
//         return dp[index];
//     }
// public:
//     string stoneGameIII(vector<int>& stoneValue) {
//         vector<int> dp(stoneValue.size()+1, INT_MIN);
//         return dfs(stoneValue, dp, 0, true) == 0 ? "Tie" 
//                 : dfs(stoneValue, dp, 0, true) > 0 ? "Alice" 
//                 : "Bob";
//     }
// };