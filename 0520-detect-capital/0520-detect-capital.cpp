class Solution {
public:
    bool detectCapitalUse(string word) {
        auto count{0};
        for (auto i = 0; i < word.size(); ++i) {
            if (isupper(word[i])) ++count;
        }
        if (count == 0 
            || count == word.size() 
            || (count == 1 && isupper(word[0]))) {
            return true;
        }
        return false;
    }
};