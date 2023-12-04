class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (auto i = 2; i < num.size(); ++i) {
            if (num[i] == num[i-1] && num[i-1] == num[i-2]) {
                if (ans.empty() || num[i] > ans[0]) {
                    ans = num.substr(i-2, 3);
                }
            }
        }
        return ans;
    }
};