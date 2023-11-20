class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        bool isNegative = x < 0;
        x = abs(x); // doing abs(INT_MIN) is UB!
        int ans = 0;
        while (x != 0) {
            if (!isNegative && ans > INT_MAX / 10) return 0;
            if (isNegative && ans * -1 < INT_MIN / 10) return 0;
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        return ans * (isNegative ? -1 : 1);
    }
};

// 1534236469
// -2147483648