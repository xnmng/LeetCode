class SeatManager {
    set<int> s; // free seats
    int index;
    int num;
public:
    SeatManager(int n) : index(1), num(n) {}
    
    // invariant: index > all elements in s
    int reserve() {
        int res;
        if (s.empty()) {
            res = index;
            ++index;
        } else {
            res = *s.begin();
            s.erase(s.begin());
        }
        return res;
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */