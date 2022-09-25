class MyCircularQueue {
    vector<int> v;
    int rem; // number of elements remaining we can insert
    int front = 0;
    int back = 0;
public:
    MyCircularQueue(int k) : v(vector<int>(k)), rem(k){}
    
    bool enQueue(int value) {
        if (isEmpty()) {
            --rem;
            v[front] = value;
            return true;
        }
        
        if (rem == 0) return false;
        ++back;
        if (back == v.size()) back = 0;
        --rem;
        v[back] = value;
        return true;
    }
    
    bool deQueue() {
        if (rem + 1 == v.size()) {
            ++rem;
            return true;
        }
        
        // should deQueue return false if vector is empty? -> YES
        if (isEmpty()) return false;
        ++front;
        if (front == v.size()) front = 0;
        ++rem;
        return true;
    }
    
    int Front() {
        // cout << front << " " << back << " " << v.size() - rem << "\n";
        if (isEmpty()) return -1;
        return v[front];
    }
    
    int Rear() {
        // cout << front << " " << back << "\n";
        
        if (isEmpty()) return -1;
        return v[back];
    }
    
    bool isEmpty() {
        return rem == v.size();
    }
    
    bool isFull() {
        return rem == 0;
    }
};

// handle edge case where we insert into empty queue! (should not be moving back index)
// ["MyCircularQueue","enQueue","Rear","Front","deQueue","Front","deQueue","Front","enQueue","enQueue","enQueue","enQueue"]
// [[3],[2],[],[],[],[],[],[],[4],[2],[2],[3]]

// handle edge case where we dequeue a queue with only 1 element (should not be moving front index)
// ["MyCircularQueue","enQueue","Rear","Rear","deQueue","enQueue","Rear","deQueue","Front","deQueue","deQueue","deQueue"]
// [[6],[6],[],[],[],[5],[],[],[],[],[],[]]

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */