class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int n;
        for (char c : s) {
            n = ans.size();
            if (ans.size() >= 2 &&
                ans[n-1] == c &&
                ans[n-2] == c) continue;
            ans += c;
        }
        return ans;
    }
};