class Solution {
public:
    int minimumLength(string s) {
        vector<int> v(26,0);
        for (char c : s) {
            ++v[c - 'a'];
        }
        int ans = 0;
        for (int i : v) {
            if (i < 2) ans += i;
            else {
                ans += i % 2 == 1 ? 1 : 2;
            }
        }
        return ans;
    }
};