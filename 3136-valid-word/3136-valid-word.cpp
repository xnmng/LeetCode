class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
        bool vowel = false;
        bool consonant = false;
        for (auto i : word) {
            i = tolower(i);
            if (i == '@' || i == '#' || i == '$') return false;
            else if (isdigit(i)) continue;
            else if (i == 'a' 
                    || i == 'e'
                    || i == 'i'
                    || i == 'o'
                    || i == 'u') vowel = true;
            else consonant = true;
        }
        return vowel && consonant;
    }
};