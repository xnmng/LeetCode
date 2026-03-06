class Solution {
public:
    int minOperations(string s) {
        // check both "1010..." and "0101..."
        // dont need 2 pass; only need 1 pass and check one of them
        // the other can be obtained by taking (s.size() - ans)
        // because each index is only either '0' or '1'
        int ans = 0;
        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] == '1') ++ans;
            if (i+1 < s.size() && s[i+1] == '0') ++ans;
        }
        return min(static_cast<int>(s.size()) - ans, ans);
    }
};