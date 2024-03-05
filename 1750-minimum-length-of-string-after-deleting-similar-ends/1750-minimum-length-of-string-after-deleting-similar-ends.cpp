class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        char cur;
        while (left < right) {
            if (s[left] != s[right]) break;
            cur = s[left];
            while (left <= right && s[left] == cur) {
                ++left;
            }
            while (left <= right && s[right] == cur) {
                --right;
            }
        }
        return right - left + 1;
    }
};