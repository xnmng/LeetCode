class Solution {
public:
    // (question didnt mention this)
    // all the digits must be in increasing order
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k > n) return {};
        vector<vector<int>> ans;
        vector<int> temp;
        temp.reserve(k);
        dfs(k, n, ans, temp);
        return ans;
    }
    
    void dfs(int k, int n, vector<vector<int>>& ans, vector<int>& temp) {
        if (k == 0) {
            if (n == 0) {
                ans.emplace_back(temp);
            }
        }
        else {
            for (int i = temp.empty() ? 1 : temp.back() + 1; i <= min(9, n); ++i) {
                temp.emplace_back(i);
                dfs(k - 1, n - i, ans, temp);
                temp.pop_back();
            }
        }
    }
};