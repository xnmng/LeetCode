class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> firstUpper(26, -1);
        vector<int> lastLower(26, -1);
        for (int i = 0; i < word.size(); ++i) {
            if (isupper(word[i]) && firstUpper[word[i] - 'A'] == -1) {
                firstUpper[word[i] - 'A'] = i;
            }
            else if (islower(word[i])) {
                lastLower[word[i] - 'a'] = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (firstUpper[i] == -1 || lastLower[i] == -1) continue;
            ans += (firstUpper[i] > lastLower[i]);
        }
        return ans;
    }
};