class Solution {
public:
    int minFlips(int a, int b, int c) {
        auto ans{0};
        while (a != 0 || b != 0 || c != 0) {
            // cout << a % 2 << " " << b % 2 << " " << c % 2 << "\n";
            if (c % 2 == 1) {
                if (a % 2 == 0 && b % 2 == 0) ++ans;
            } else {
                if (a % 2 == 1) ++ans;
                if (b % 2 == 1) ++ans;
            }
            a /= 2;
            b /= 2;
            c /= 2;
            // cout << ans << "\n";
        }
        return ans;
    }
};