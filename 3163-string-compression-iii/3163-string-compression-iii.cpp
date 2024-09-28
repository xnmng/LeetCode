class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        char cur = ' ';
        int count = 0;
        for (char c : word) {
            if (cur != c) {
                if (count > 0) ans += to_string(count) + cur;
                cur = c;
                count = 1;
            }
            else {
                ++count;
                if (count == 9) {
                    ans += to_string(count) + cur;
                    count = 0;
                }
            }
        }
        if (count > 0) ans += to_string(count) + cur;
        return ans;
    }
};