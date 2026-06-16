class Solution {
public:
    string processStr(string s) {
        string ans;
        for (char c : s) {
            if (c == '*') {
                if (ans.size() > 0) ans.pop_back();
            }
            else if (c == '#') ans += ans;
            else if (c == '%') reverse(ans.begin(), ans.end());
            else ans += c;
        }
        return ans;
    }
};