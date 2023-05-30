class MyHashSet {
private:
    vector<vector<pair<int,int>>> v;
public:
    MyHashSet() : v(7) {}
    
    void add(int key) {
        if (contains(key)) return;
        v[key % 7].emplace_back(key, 1);
    }
    
    void remove(int key) {
        for (auto& i : v[key % 7]) {
            if (i.first == key && i.second == 1) {
                i.second = -1;
                break;
            }
        }
    }
    
    bool contains(int key) {
        for (auto& i : v[key % 7]) {
            if (i.first == key && i.second == 1) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */