class Solution {
public:
    // https://leetcode.com/problems/lexicographical-numbers/discuss/86288/7-lines-simple-C++-recursive-solution
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        ans.reserve(n);
        dfs(1, n, ans);
        return ans;
    }
    
    void dfs(int cur, int n, vector<int>& ans) {
        if (cur > n) return;
        ans.emplace_back(cur);
        dfs(cur * 10, n, ans);
        if (cur % 10 != 9) dfs(cur + 1, n, ans);
    }
};