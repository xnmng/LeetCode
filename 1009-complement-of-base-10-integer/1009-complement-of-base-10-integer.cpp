class Solution {
public:
    int bitwiseComplement(int n) {
        int x = 1;
        if (n < 2) return x ^ n;
        while (x <= n) x *= 2;
        return (x - 1) ^ n;
    }
};