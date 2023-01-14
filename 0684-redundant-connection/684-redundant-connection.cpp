class Solution {
private:
    int findParent(vector<int>& parent, int index) {
        // cout << index << "\n";
        if (parent[index] == -1) {
            parent[index] = index;
            return index;
        }
        if (parent[index] == index) return index;
        parent[index] = findParent(parent, parent[index]);
        return parent[index];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1, -1);
        for (auto i : edges) {
            if (findParent(parent, i[0]) == findParent(parent, i[1])) return i;
            parent[findParent(parent, i[0])] = findParent(parent, i[1]);
        }
        return {}; // should not happen
    }
};