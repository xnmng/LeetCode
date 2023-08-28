// https://leetcode.com/problems/implement-stack-using-queues/solution/
/*
3 approaches:

1. 2 queues; push O(n), pop O(1)
    keep 1 queue empty (q1) and 1 queue with all the elements
    push(): push new element to empty queue, push all elements from full queue to empty queue
    pop(): remove element from non-empty queue (if it exists)
    e.g.
    (add 1)
    q1:
    q2: 1
    
    (add 2)
    q1: 2, 1
    q2:
    
    (add 3)
    q1:
    q2: 3, 2, 1
    
2. 2 queues; push O(1), pop O(n)
    keep 1 queue empty (q1) and 1 queue with all the elements
    push(): add new element to non-empty queue
    pop(): move elements from non-empty to empty queue, 
        return last element in initial non-empty queue
    e.g.
    (add 1)
    q1: 1
    q2:
    
    (add 2)
    q1: 1, 2
    q2:
    
    (add 3)
    q1: 1, 2, 3
    q2:
    
    (pop)
    q1: 3 (return this)
    q2: 1, 2
    
3. 1 queue - push O(1), pop O(n)
    push(): add new element to back of queue
    pop(): if queue contains n elements, 
        move first n-1 elements from front to back of queue, 
        return nth element
    e.g.
    (add 1)
    q1: 1

    (add 2)
    q1: 1, 2

    (add 3)
    q1: 1, 2, 3

    (pop)
    q1: 3 (return this), 1, 2
*/
class MyStack {
private:
    queue<int> s1; // push
    queue<int> s2; // pop
public:
    MyStack() {}
    
    void push(int x) {
        if (s1.empty()) {
            s1.push(x);
            while (!s2.empty()) {
                s1.push(s2.front());
                s2.pop();
            }
        }
        else {
            s2.push(x);
            while (!s1.empty()) {
                s2.push(s1.front());
                s1.pop();
            }
        }
    }
    
    int pop() {
        int ans{-1};
        if (s1.empty()) {
            ans = s2.front();
            s2.pop();
        } else if (s2.empty()) {
            ans = s1.front();
            s1.pop();
        }
        return ans;
    }
    
    int top() {
        if (s1.empty()) return s2.front();
        if (s2.empty()) return s1.front();
        return -1; // should not happen
    }
    
    bool empty() {
       return s1.empty() && s2.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
