class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0;
        while (n > 0) {
            ans -= n % 10;
            n /= 10;
            if (n == 0) {
                ans *= -1;
            }
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
};
// 10