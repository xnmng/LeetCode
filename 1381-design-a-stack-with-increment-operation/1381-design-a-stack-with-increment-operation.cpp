// https://leetcode.com/problems/design-a-stack-with-increment-operation/discuss/539716/JavaC++Python-Lazy-increment-O(1)

class CustomStack {
private:
    vector<int> v;
    vector<int> offsetv;
    int count;
public:
    CustomStack(int maxSize) : count(maxSize) {}

    void push(int x) {
        if (v.size() == count) return;
        v.push_back(x);
        offsetv.push_back(0);
    }

    int pop() {
        auto index{static_cast<int>(v.size())-1};
        if (index < 0) return -1;
        if (index > 0) offsetv[index-1] += offsetv[index];
        auto ans{v[index] + offsetv[index]};
        v.pop_back();
        offsetv.pop_back();
        return ans;
    }
    
    void increment(int k, int val) {
        auto index{min(static_cast<int>(v.size()), k) - 1};
        if (index >= 0) offsetv[index] += val;
    }
};

// https://leetcode.com/submissions/detail/916608976/testcase/

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */