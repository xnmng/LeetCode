// https://leetcode.com/problems/implement-queue-using-stacks/solutions/64206/short-o-1-amortized-c-java-ruby/
class MyQueue {
    stack<int> in;
    stack<int> out;
public:
    MyQueue() {}
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        peek();
        auto ans{out.top()};
        out.pop();
        return ans;
    }
    
    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */