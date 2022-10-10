class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() == 1) return "";
        for (auto i = 0; i < palindrome.size(); ++i) {
            if (palindrome.size() % 2 == 1 && i == palindrome.size() / 2) continue;
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome.back() = 'b';
        return palindrome;
    }
};

// aba