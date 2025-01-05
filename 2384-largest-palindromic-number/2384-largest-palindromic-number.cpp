class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> v(10, 0);
        for (char c : num) ++v[c - '0'];
        int anslen = 0;
        bool hasodd = false;
        for (int i = 1; i < 10; ++i) {
            anslen += v[i] / 2;
            hasodd |= v[i] % 2 == 1;
        }

        // handle edge cases of single digit
        if (anslen == 0) {
            for (int i = 9; i >= 0; --i) {
                if (v[i] > 0) return string(1, '0' + i);
            }
        }

        anslen += v[0] / 2;
        hasodd |= v[0] % 2 == 1;
        int n = 2 * anslen + hasodd;
        string ans(n, '0');
        int next = 0;
        for (int i = 9; i >= 0; --i) {
            for (int j = 0; j < v[i] / 2; ++j) {
                ans[next] = '0' + i;
                ans[n-1-next] = '0' + i;
                ++next;
            }
            if (v[i] % 2 == 1 && hasodd) {
                hasodd = false;
                ans[n / 2] = '0' + i;
            }
        }
        return ans;
    }
};