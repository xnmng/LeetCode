// https://youtu.be/HsLG5QW9CFQ
class Solution {
private:
    int dfs(vector<int>& stoneValue, vector<int>& dp, int index, bool isAlice) {
        if (index == stoneValue.size()) return 0;
        if (dp[index] != INT_MIN) return dp[index];
        auto val{INT_MIN};
        auto sum{0};
        for (auto i = 0; i < 3; ++i) {
            if (index + i == stoneValue.size()) break;
            sum += stoneValue[index + i];
            val = max(val, sum - dfs(stoneValue, dp, index+i+1, !isAlice));                
        }
        dp[index] = val;
        return dp[index];
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size()+1, INT_MIN);
        return dfs(stoneValue, dp, 0, true) == 0 ? "Tie" 
                : dfs(stoneValue, dp, 0, true) > 0 ? "Alice" 
                : "Bob";
    }
};