class Solution {
private:
    bool isVowel(char& c) {
        return c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u' ||
        c == 'A' ||
        c == 'E' ||
        c == 'I' ||
        c == 'O' ||
        c == 'U';
    }
public:
    string reverseVowels(string s) {
        auto left{0};
        auto right{static_cast<int>(s.size()-1)};
        while (left <= right) {
            // cout << left << " " << right << "\n";
            if (isVowel(s[left]) && isVowel(s[right])) {
                swap(s[left], s[right]);
                ++left;
                --right;
            }
            else {
                if (!isVowel(s[left])) ++left;
                if (!isVowel(s[right])) --right;                
            }
        }
        return s;
    }
};
// "aA"
// " "