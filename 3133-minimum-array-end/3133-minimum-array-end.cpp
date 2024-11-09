class Solution {
public:
    long long minEnd(int n, int x) {
        --n; // include x itself
        long long ans = x;
        for (int i = 0; i < 64 && n > 0; ++i) {
            if ((ans & (1ll << i)) == 0) {
                // cout << i << "\n";
                if (n % 2 == 1) {
                    ans |= (1ll << i);
                }
                n /= 2;
            }
        }
        return ans;
    }
};
// 6715154
// 7193485