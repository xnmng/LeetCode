class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (!isalpha(s[left]) && !isdigit(s[left])) ++left;
            else if (!isalpha(s[right]) && !isdigit(s[right])) --right;
            else if (tolower(s[left]) == tolower(s[right])) {
                ++left;
                --right;
            }
            else return false;
        }
        return true;
    }
};
// "0P"