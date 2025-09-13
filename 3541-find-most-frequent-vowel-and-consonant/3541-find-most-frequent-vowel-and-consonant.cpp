class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> chars(26, 0);
        int vowel = 0;
        int consonant = 0;
        for (char c : s) {
            ++chars[c - 'a'];
            if (check(c)) {
                vowel = max(vowel, chars[c - 'a']);
            }
            else consonant = max(consonant, chars[c - 'a']);
        }
        return vowel + consonant;
    }

    bool check(char c) {
        return c == 'a' ||
            c == 'e' || 
            c == 'i' || 
            c == 'o' || 
            c == 'u';
    }
};