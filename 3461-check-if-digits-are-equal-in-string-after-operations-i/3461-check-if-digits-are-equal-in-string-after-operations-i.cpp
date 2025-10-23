class Solution {
public:
    bool hasSameDigits(string s) {
        string next = "";
        int temp;
        while (s.size() != 2) {
            for (int i = 1; i < s.size(); ++i) {
                temp = ((s[i] - '0') + (s[i-1] - '0')) % 10;
                next.push_back('0' + temp);
            }
            swap(s, next);
            next.clear();
        }
        return s[0] == s[1];
    }
};