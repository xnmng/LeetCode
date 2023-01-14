class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        long a;
        long b;
        for (auto& i : tokens) {
            if (i == "+" ||
            i == "-" || 
            i == "*" || 
            i == "/") {
                b = s.top();
                s.pop();
                a = s.top(); s.pop();
                if (i == "+") s.push(a+b);
                else if (i == "-") s.push(a-b);
                else if (i == "*") s.push(a*b);
                else s.push(a/b);
            } else {
                s.push(stol(i));
            }
        }
        return s.top();
    }
};

// ["-128","-128","*","-128","*","-128","*","8","*","-1","*"]