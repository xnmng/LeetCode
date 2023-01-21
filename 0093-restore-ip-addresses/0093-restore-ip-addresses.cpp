class Solution {
private:
    void dfs(string& s, vector<string>& cur, vector<string>& ans, int index) {
        if (cur.size() == 4) {
            if (index == s.size()) {
                ans.emplace_back("" + cur[0] + "." + cur[1] + "." + cur[2] + "." + cur[3]);
            }
        }
        else if (s[index] == '0') {
            cur.push_back("0");
            dfs(s, cur, ans, index+1);
            cur.pop_back();
        }
        else {
            int num;
            for (auto i = 1; i <= 3 && index + i <= s.size(); ++i) {
                num = stoi(s.substr(index, i));
                if (num > 0 && num <= 255) {
                    cur.push_back(to_string(num));
                    dfs(s, cur, ans, index + i);
                    cur.pop_back();
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> v;
        dfs(s, v, ans, 0);
        return ans;
    }
};