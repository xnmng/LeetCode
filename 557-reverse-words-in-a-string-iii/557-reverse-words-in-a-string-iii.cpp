// https://leetcode.com/problems/reverse-words-in-a-string-iii/discuss/664562/Simple-and-Clean-C++-solution-(in-place)
class Solution {
public:
    string reverseWords(string s) {
        auto index{0};
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + index, s.begin() + i);
                index = i+1;
            }
        }
        reverse(s.begin() + index, s.end());
        return s;
    }
};