class Solution {
public:
    double myPow(double x, int n) {
        bool isNegative{n < 0};
        n = abs(n);
        double ans{1};
        double cur{x};
        while (n > 0) {
            if (n % 2 == 1) {
                ans *= cur;
            }
            cur *= cur;
            n /= 2;
        }
        return isNegative ? 1/ans : ans;
    }
};