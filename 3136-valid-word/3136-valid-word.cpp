class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
        bool hasConsonant = false;
        bool hasVowel = false;
        for (char c : word) {
            if (isdigit(c)) continue;
            if (!isalpha(c)) return false;
            // is alphabet
            c = tolower(c);
            if (isvowel(c)) hasVowel = true;
            else hasConsonant = true;
        }
        return hasVowel && hasConsonant;
    }

    bool isvowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};