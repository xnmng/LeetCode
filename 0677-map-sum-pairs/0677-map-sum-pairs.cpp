class MapSum {
private:
    unordered_map<string, int> ump; // stores prefix val
    unordered_map<string, int> kvmp; // stores initial input
public:
    MapSum() {}
    
    void insert(string key, int val) {
        if (kvmp.find(key) == kvmp.end()) {
            kvmp[key] = val;
            while (!key.empty()) {
                ump[key] += val;
                key.pop_back();
            }
        } else {
            int diff{val - kvmp[key]};
            kvmp[key] = val;
            while (!key.empty()) {
                ump[key] += diff;
                key.pop_back();
            }
        }
    }
    
    int sum(string prefix) {
        return ump[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

// ["MapSum","insert","sum","insert","insert","sum"]
// [[],["apple",3],["ap"],["app",2],["apple",2],["ap"]]