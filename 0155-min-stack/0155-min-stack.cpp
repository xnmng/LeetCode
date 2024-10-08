// we want to implement both a stack and able to obtain minimum element in constant time
// use vector to implement stack (container adapter)
//
// instead of just storing the pushed val, 
// store both the pushed val and the smallest element in the stack at that point the element was added
class MinStack {
    vector<pair<int,int>> v; // <val, minimum_element>
    int minimum;
public:
    MinStack() : v(), minimum(INT_MAX) {}
    
    void push(int val) {
        minimum = min(minimum, val);
        v.emplace_back(val, minimum);
    }
    
    void pop() {
        v.pop_back();
        minimum = getMin();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        if (v.empty()) return INT_MAX;
        return v.back().second;
    }
};

// // could also implement this as just 2 stacks/vectors; idea is the same
// class MinStack {
//     stack<int> s;
//     stack<int> min;
// public:
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if (min.empty() || min.top() >= val) {
//             min.push(val);
//         }
//         s.push(val);
//     }
    
//     void pop() {
//         int top = s.top();
//         if (top == min.top()) {
//             min.pop();
//         }
//         s.pop();
//     }
    
//     int top() {
//         return s.top();
//     }
    
//     int getMin() {
//         return min.top();
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */