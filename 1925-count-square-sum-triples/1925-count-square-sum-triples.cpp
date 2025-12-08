class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        double k;
        for (int i = 1; i <= n; ++i) {
            // dont need to iterate j from 1;
            // if (i, j) sums up to some valid k,
            // then (j, i) also sums up to k
            for (int j = i + 1; j <= n; ++j) {
                k = sqrt(i * i + j * j);
                if (k > n) break;
                if (k == (int) k) ans += 2;
            }
        }
        return ans;
    }
};