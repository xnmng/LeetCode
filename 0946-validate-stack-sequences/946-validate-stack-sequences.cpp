class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        auto pushIndex{0};
        auto popIndex{0};
        while (pushIndex < pushed.size() && popIndex < popped.size()) {
           if (!s.empty() && s.top() == popped[popIndex]) {
                    ++popIndex;
                    s.pop();
            } else {
                s.push(pushed[pushIndex]);
                ++pushIndex;
            }
        }
        while (popIndex < popped.size()) {
            if (popped[popIndex] != s.top()) {
                return false;
            }
            s.pop();
            ++popIndex;
        }
        return true;
    }
};