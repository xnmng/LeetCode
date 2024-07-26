class Solution {
public:
    // All Pair Shortest Path (APSP) algorithm (Floyd-Warshall)
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // max edge weight 1e4, max nodes 1e2 -> maximum possible walk 1e6
        vector<vector<int>> dist(n, vector<int>(n, 1e7));
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0; // distance to itself is zero
        }
        for (auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        
        // floyd warshall algo
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Update shortest path from i to j through k
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int count = INT_MAX;
        int ans = -1;
        int temp;
        
        // find answer, starting from the back because,
        // If there are multiple such cities, return the city with the greatest number.
        for (int i = n-1; i >= 0; --i) {
            temp = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    ++temp;        
                }
            }
            if (temp < count) {
                ans = i;
                count = temp;
            }
        }
        return ans;
    }
};