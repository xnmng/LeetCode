class Solution {
public:
    long long coloredCells(int n) {
        long long square = (2ll * n - 1) * (2ll * n - 1);
        long long triangle = 1ll * (n-1) * n / 2;
        return square - 4 * triangle;
    }
};
// 69675