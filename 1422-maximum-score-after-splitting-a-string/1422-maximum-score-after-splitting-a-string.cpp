class Solution {
public:
    int maxScore(string s) {
        int oneCount = 0;
        for (char c : s) {
            if (c == '1') ++oneCount;
        }
        int ans = 0;
        int zeroCount = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') ++zeroCount;
            else --oneCount;
            ans = max(ans, zeroCount + oneCount);
        }
        return ans;
    }
};
// "00"