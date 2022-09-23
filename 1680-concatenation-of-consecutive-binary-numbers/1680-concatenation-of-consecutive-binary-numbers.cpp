// https://youtu.be/ttlNQ6YrdGs
class Solution {
public:
    int concatenatedBinary(int n) {
        auto ans{0l};
        auto bits{0};
        for (auto i = 1; i <= n; ++i) {
            bits = log2(i) + 1;
            ans <<= bits;
            ans += i;
            ans %= (long)(1e9 + 7);
        }
        return ans;
    }
};