class Solution {
private:
    int dfs(int n, unordered_map<int,int>& mp) {
        if (n == 1) return 0;
        if (mp.find(n) != mp.end()) return mp[n];
        
        if (n % 2 == 0) mp[n] = 1 + dfs(n/2, mp);
        else {
            // to avoid overflow, /2 then perform addition/subtraction (overall +2 instead)
            // positive odd number can be represented as (2k+1), k > 0
            // after 2 steps, becomes either k+1 or k
            mp[n] = 2 + min(dfs(n/2 + 1, mp), dfs(n/2, mp));
        }
        return mp[n];
    }
public:
    int integerReplacement(int n) {
        unordered_map<int, int> mp;
        dfs(n, mp);
        return mp[n];
    }
};

// 2147483647