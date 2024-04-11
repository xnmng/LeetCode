class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";
        string ans = "";
        int n = num.size();
        for (int i = 0; i < n; ++i) {
            while (k > 0 && !ans.empty() && ans.back() > num[i]) {
                --k;
                ans.pop_back();
            }
            if (k == 0) {
                ans += num.substr(i);
                break;
            }
            ans += num[i];
        }
        while (k > 0) {
            ans.pop_back();
            --k;
        }
        for (int i = 0; i < ans.size(); ++i) {
            if (ans[i] == '0') continue;
            return ans.substr(i);
        }
        return "0";
    }
};
// "112"
// 1
// "9"
// 1