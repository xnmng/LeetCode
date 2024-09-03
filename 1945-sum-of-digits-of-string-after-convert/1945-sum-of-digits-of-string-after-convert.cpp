class Solution {
public:
    // simulate the process
    int getLucky(string s, int k) {
        string cur;
        for (char c : s) {
            cur += to_string(c - 'a' + 1); // 'a' is mapped to 1, not 0!
        }
        int ans = 0;
        for (char c : cur) {
            ans += c - '0';
        }
        int temp;
        for (int i = 0; i < k-1; ++i) {
            temp = ans;
            ans = 0;
            while (temp > 0) {
                ans += temp % 10;
                temp /= 10;
            }
        }
        return ans;
    }
};