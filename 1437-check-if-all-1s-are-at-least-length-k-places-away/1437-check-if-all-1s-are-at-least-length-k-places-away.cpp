class Solution {
public:
    string smallestString(string s) {
        auto left{0};
        while (s[left] == 'a') ++left;
        while (left < s.size()) {
            if (s[left] == 'a') break;
            --s[left];
            ++left;
        }
        return s;
    }
};