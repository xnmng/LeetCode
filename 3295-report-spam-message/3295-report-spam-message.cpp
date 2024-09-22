class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> s(bannedWords.begin(), bannedWords.end());
        int count = 0;
        for (auto& str : message) {
            if (s.find(str) != s.end()) ++count;
        }
        return count >= 2;
    }
};