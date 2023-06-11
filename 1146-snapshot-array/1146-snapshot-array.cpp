class SnapshotArray {
private:
    vector<vector<pair<int,int>>> v; // (id, value)
    int id;
public:
    SnapshotArray(int length) : v(length, vector<pair<int,int>>({make_pair(0,0)})), id(0) {}
    
    void set(int index, int val) {
        if (v[index].back().second == val) return;
        if (v[index].back().first == id) {
            v[index].back().second = val;
            return;
        }
        v[index].emplace_back(id, val);
    }
    
    int snap() {
        ++id;
        return id-1;
    }
    
    int get(int index, int snap_id) {
        auto itr{
            prev(
                upper_bound(
                    v[index].begin(), 
                    v[index].end(), 
                    make_pair(snap_id, INT_MAX)))};
        // cout << index << " " << snap_id << "\n";
        // cout << itr->first << " " << itr->second << "\n";
        return itr->second;
    }
};

// ["SnapshotArray","snap","snap","get","set","snap","set"]
// [[4],[],[],[3,1],[2,4],[],[1,4]]
// ["SnapshotArray","set","snap","snap","set","set","get","get","get"]
// [[3],[1,6],[],[],[1,19],[0,4],[2,1],[2,0],[0,1]]

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */