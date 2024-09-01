class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans = 0;
        ans += min(num1 % 10, min(num2 % 10, num3 % 10));
        ans += 10 * min(num1 % 100 / 10, min(num2 % 100 / 10, num3 % 100 / 10));
        ans += 100 * min(num1 % 1000 / 100, min(num2 % 1000 / 100, num3 % 1000 / 100));
        ans += 1000 * min(num1 / 1000, min(num2 / 1000, num3 / 1000));
        return ans;
    }
};