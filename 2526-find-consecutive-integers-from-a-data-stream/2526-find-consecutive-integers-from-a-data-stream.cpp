class DataStream {
private:
    int value;
    int k;
    int cur;
    int prev; // prev index not matching value
public:
    DataStream(int value, int k) : value(value), k(k), cur(0), prev(-1) {}
    
    bool consec(int num) {
        if (num != value) prev = cur;
        ++cur;
        // cout << num << " " << prev << " " << cur << "\n";
        if (cur - prev > k && cur >= k) return true;
        return false;
    }
};

// ["DataStream","consec","consec","consec","consec","consec"]
// [[1,2],[1],[2],[1],[1],[1]]

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */