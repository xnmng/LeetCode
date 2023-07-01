class Solution {
private:
    void dfs(vector<int>& cookies, int index, vector<int>& v, int& ans) {
        if (index == cookies.size()) {
            auto val{INT_MIN};
            for (auto& i : v) val = max(val, i);
            ans = min(ans, val);
            return;
        }
        bool hasAdd{false};
        for (auto i = 0; i < v.size(); ++i) {
            v[i] += cookies[index];
            dfs(cookies, index+1, v, ans);
            v[i] -= cookies[index];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k, 0);
        auto ans{INT_MAX};
        dfs(cookies, 0, v, ans);
        return ans;
    }
};

// [20,13,18]
// 2
// [4,13,7,14,8]
// 3