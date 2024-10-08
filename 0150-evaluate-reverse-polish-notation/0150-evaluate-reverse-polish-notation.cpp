// E4 capital round 1 interview question (timothy)
class Solution {
public:
    // The reverse polish is a mathematical notation in which operators follow their operands. 
    // we will get the operands first and then the operators.

    // So, we need to store all the previous operands in order that we receive. 
    // If we get a operator at anytime, we know that it must be operated on the previous two operands. 
    // The result that we get will act as operand for future operations and so it must be stored as well. 
    // We can use a stack to store all the operands. 

    // The algorithm can be summarized as:
    //     - If the current token is a operand (number), push it into the stack
    //     - If the token is a operator, pop the top two operands from the stack. 
    //         Find the result of the operation using the operator and two operands and push the result back into stack
    //     - Finally, the stack will contain the result of evaluated reverse polish expression.
    //
    // We can also use input as stack if we want to (technically) get O(1) space
    // https://leetcode.com/problems/evaluate-reverse-polish-notation/discuss/1229370/Short-and-Simple-Solution-w-Explanation-or-O(N)-and-O(1)-Space-Solutions
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