class Solution {
public:
    string truncateSentence(string s, int k) {
        auto count{1};
        for (auto i = 0; i < s.size(); ++i) {
            if (count == k && s[i] == ' ') {
                return s.substr(0, i);
            } else if (s[i] == ' ') ++count;
        }
        return s;
    }
};