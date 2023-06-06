class RLEIterator {
private:
    int index;
    int count;
    vector<int> data;
public:
    RLEIterator(vector<int>& encoding) : index(0), count(0), data(encoding) {}
    
    int next(int n) {
        count += n-1;
        while (index < data.size() && count >= data[index]) {
            count -= data[index];
            index += 2;
        }
        if (index >= data.size()) return -1;
        ++count;
        return data[index+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */