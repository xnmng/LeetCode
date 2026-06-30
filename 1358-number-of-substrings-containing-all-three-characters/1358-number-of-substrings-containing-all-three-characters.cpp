class Solution {
public:
    // https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/editorial
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> last(3, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
            ans += 1 + min({last[0], last[1], last[2]});
        }
        return ans;
    }
};