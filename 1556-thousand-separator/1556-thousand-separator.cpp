class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) return "0";
        string ans;
        int count{0};
        while (n > 0) {
            ans += to_string(n % 10);
            ++count;
            n /= 10;
            if (count == 3 && n > 0) {
                count = 0;
                ans += ".";
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 123456789