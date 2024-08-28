class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long> v(n, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            v[edges[i]] += i;
            if (v[edges[i]] > v[ans] || 
                (v[edges[i]] == v[ans] && edges[i] < ans)) ans = edges[i];
        }
        return ans;
    }
};
// [3,3,3,0]