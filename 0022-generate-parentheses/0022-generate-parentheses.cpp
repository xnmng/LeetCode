class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string cur = "("; // any valid str starts with '('
        int left = n-1;
        int right = n;
        dfs(left, right, cur, v);
        return v;
    }

    void dfs(int left, int right, string& cur, vector<string>& v) {
        if (left == 0 && right == 0) {
            v.emplace_back(cur);
            return;
        }
        if (left >= 0) {
            cur += '(';
            dfs(left - 1, right, cur, v);
            cur.pop_back();
        }
        if (right > left) {
            cur += ')';
            dfs(left, right - 1, cur, v);
            cur.pop_back();
        }
    }
};