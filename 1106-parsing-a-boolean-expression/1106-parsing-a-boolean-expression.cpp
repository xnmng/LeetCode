class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        int t;
        int f;
        char op;
        char cur;
        for (auto i : expression) {
            if (i == ')') {
                t = 0;
                f = 0;
                while (true) {
                    cur = s.top();
                    s.pop();
                    if (cur == 't') ++t;
                    else if (cur == 'f') ++f;
                    else if (cur == '(') {
                        op = s.top();
                        s.pop();
                        break;
                    } 
                }
                if (op == '&') {
                    f > 0 ? s.push('f') : s.push('t');
                }
                else if (op == '|') {
                    t > 0 ? s.push('t') : s.push('f');
                }
                else if (op == '!') {
                    t > 0 ? s.push('f') : s.push('t');
                }
            }
            else s.push(i);
        }
        return s.top() == 'f' ? false : true;
    }
};