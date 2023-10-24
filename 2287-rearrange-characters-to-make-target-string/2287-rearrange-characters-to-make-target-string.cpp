class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> v1(26, 0);
        for (auto i : target) {
            ++v1[i - 'a'];
        }
        vector<int> v2(26, 0);
        for (auto i : s) {
            ++v2[i - 'a'];
        }
        int ans = INT_MAX;
        for (auto i = 0; i < 26; ++i) {
            if (v1[i] != 0) {
                ans = min(ans, v2[i] / v1[i]);
            }
            if (ans == 0) break;
        }
        return ans;
    }
};