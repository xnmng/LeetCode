class Solution {
    void dfs(string& s, int n, int k, vector<int>& ans) {
        if (s.size() == n) {
            ans.push_back(stoi(s));
            return;
        }
        if (s.back() + k <= '9' && s.back() + k >= '0') {
            s.push_back(s.back() + k);
            dfs(s, n, k, ans);
            s.pop_back();
        }
        if (k != 0 && s.back() - k <= '9' && s.back() - k >= '0') {
            s.push_back(s.back() - k);
            dfs(s, n, k, ans);
            s.pop_back();
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        string cur;
        for (auto i = '1'; i <= '9'; ++i) {
            cur = i;
            dfs(cur, n, k, ans);
        }
        return ans;
    }
};

// 2
// 0