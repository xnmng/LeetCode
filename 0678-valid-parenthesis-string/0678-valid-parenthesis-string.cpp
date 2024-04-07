class Solution {
public:
    bool checkValidString(string s) {
        int wildcard = 0;
        int count = 0;
        for (char c : s) {
            if (c == '*') ++wildcard;
            else if (c == '(') ++count;
            if (c == ')') {
                if (count == 0) {
                    if (wildcard == 0) return false;
                    --wildcard;
                }
                else --count;
            }
        }
        if (count > 0 && wildcard < count) return false;
        wildcard = 0;
        count = 0;
        for (auto itr = s.rbegin(); itr != s.rend(); ++itr) {
            char c = *itr;
            if (c == '*') ++wildcard;
            else if (c == ')') ++count;
            if (c == '(') {
                if (count == 0) {
                    if (wildcard == 0) return false;
                    --wildcard;
                }
                else --count;
            }
        }
        if (count > 0 && wildcard < count) return false;
        return true;
    }
};
// "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"