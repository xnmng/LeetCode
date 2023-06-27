class Solution {
public:
    int longestContinuousSubstring(string s) {
        auto ans{1};
        auto count{1};
        for (auto i = 1; i < s.size(); ++i) {
            if (s[i] - s[i-1] == 1) {
                ++count;
            } else {
                count = 1;
            }
            ans = max(ans, count);
            if (ans == 26) break;
        }
        return ans;
    }
};