class Solution {
public:
    int countDigits(int num) {
        string digits = to_string(num);
        int ans = 0;
        for (char c : digits) {
            if (num % (c - '0') == 0) ++ans;
        }
        return ans;
    }
};