class Solution {
public:
    int countHomogenous(string s) {
        int modulo = 1e9 + 7;
        int ans = 0;
        int count = 0;
        char c = ' ';
        for (auto i : s) {
            if (c != i) {
                c = i;
                count = 1;
            } else {
                ++count;
            }
            ans = (ans + count) % modulo;
        }
        return ans;
    }
};