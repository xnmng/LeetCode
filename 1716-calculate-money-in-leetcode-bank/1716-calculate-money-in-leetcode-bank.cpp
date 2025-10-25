class Solution {
public:
    int totalMoney(int n) {
        int a = n / 7;
        int b = n % 7;
        int ans = a * ((8 * 7) / 2) + (a * (a - 1) / 2) * 7;
        // if (b == 0) return ans;
        return ans + b * a + b * (b + 1) / 2;
    }
};
/*

1 2 3 4 5 6 7 = (0 * 7) + (1 + 2 + 3 + 4 + 5 + 6 + 7)
2 3 4 5 6 7 8 = (1 * 7) + (1 + 2 + 3 + 4 + 5 + 6 + 7)
3 4 5 6 7 8 9 = (2 * 7) + (1 + 2 + 3 + 4 + 5 + 6 + 7)

*/