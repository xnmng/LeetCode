// https://leetcode.com/problems/reverse-words-in-a-string/discuss/1531693/C++-2-solutions-O(1)-space-Picture-explain-Clean-and-Concise
class Solution {
public:
    string reverseWords(string s) {
        auto next{0};
        auto left{0};
        auto right{0};
        while (right < s.size()) {
            if (s[right] != ' ') {
                if (next != 0) {
                    s[next] = ' ';
                    ++next;
                }
                left = next;
                while (right < s.size() && s[right] != ' ') {
                    s[next] = s[right];
                    ++next;
                    ++right;
                }
                reverse(s.begin() + left, s.begin() + next);
            }
            ++right;
        }
        s.resize(next);
        reverse(s.begin(), s.end());
        return s;
    }
};

// " asdasd df f"