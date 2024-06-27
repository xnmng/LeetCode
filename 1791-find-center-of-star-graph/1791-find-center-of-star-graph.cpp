class Solution {
public:
    // if we assume star graph is valid, can do in constant time
    int findCenter(vector<vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] 
            || edges[0][0] == edges[1][1]) return edges[0][0];
        return edges[0][1];
    }
    // int findCenter(vector<vector<int>>& edges) {
    //     unordered_map<int,int> mp;
    //     for (auto i : edges) {
    //         ++mp[i[0]];
    //         ++mp[i[1]];
    //     }
    //     for (auto [k,v] : mp) {
    //         if (v == edges.size()) return k;
    //     }
    //     return -1;
    // }
};