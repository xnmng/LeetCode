class Solution {
private:
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1) return i;
        parent[i] = find(parent, parent[i]);
        return parent[i];
    }
    
    void unionPair(vector<int>& parent, vector<int>& rank, int i, int j) {
        auto x{find(parent, i)};    
        auto y{find(parent, j)};    
        if (x == y) return;
        if (rank[x] == rank[y]) {
            ++rank[x];
            parent[y] = x;
        }
        else rank[x] > rank[y] ? parent[y] = x : parent[x] = y;
    }
    
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // sort based on the edge distance
        sort(edgeList.begin(), edgeList.end(), 
            [](vector<int>& a, vector<int>& b) {
                return a[2] < b[2];   
            });
        
        // union find
        vector<int> parent(n, -1);
        vector<int> rank(n, 0);
        
        // maintain index of each query (before sorting based on limit)
        for (auto i = 0; i < queries.size(); ++i) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(),
            [](vector<int>& a, vector<int>& b) {
                    return a[2] < b[2];
            });
        
        vector<bool> ans(queries.size());
        auto edgeIndex{0};
        
        // (pj, qj, limit, index)
        for (auto i : queries) {
            auto upperBound{i[2]};
            while (edgeIndex < edgeList.size() && edgeList[edgeIndex][2] < upperBound) {
                unionPair(parent, rank, edgeList[edgeIndex][0], edgeList[edgeIndex][1]);
                ++edgeIndex;
            }
            ans[i[3]] = find(parent, i[0]) == find(parent, i[1]);
        }
        
        return ans;
    }
};