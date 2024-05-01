class Solution {
public:
    string reversePrefix(string word, char ch) {
        for (auto itr = word.begin(); itr != word.end(); ++itr) {
            if (*itr == ch) {
                reverse(word.begin(), itr+1);
                break;
            }
        }
        return word;
    }
};