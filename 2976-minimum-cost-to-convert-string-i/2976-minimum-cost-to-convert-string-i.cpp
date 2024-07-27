class Solution {
public:
    // floyd-warshall to determine all pairs shortest path, then calculate ans
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        int m = original.size();
        long long ans = 0;
        vector<vector<int>> v(26, vector<int>(26, 1e9));
        for (int i = 0; i < 26; ++i) v[i][i] = 0;
        for (int i = 0; i < m; ++i) {
            // might have duplicate mappings; use the 'cheapest' one
            v[original[i] - 'a'][changed[i] - 'a'] = min(v[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }
        
        for (auto i = 0; i < n; ++i) {
            if (v[source[i] - 'a'][target[i] - 'a'] == 1e9) return -1;
            ans += v[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};