class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long xrev = 0;
        int temp = x;
        while (temp > 0) {
            xrev *= 10;
            xrev += temp % 10;
            temp /= 10;
        }
        while (x > 0) {
            if (x % 10 != xrev % 10) return false;
            x /= 10;
            xrev /= 10;
        }
        return true;
    }
};