class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int modulo = 12345;
        vector<int> prefix(m * n);
        vector<int> suffix(m * n);
        int cur = 1;
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                grid[i][j] = grid[i][j] % modulo;
                cur = (cur * grid[i][j]) % modulo;
                prefix[i * n + j] = cur;
            }
        }
        // for (auto i : prefix) cout << i << " ";
        // cout << "\n";        
        cur = 1;
        for (auto i = m-1; i >= 0; --i) {
            for (auto j = n-1; j >= 0; --j) {
                cur = (cur * grid[i][j]) % modulo;
                suffix[i * n + j] = cur;
            }
        }
        // for (auto i : suffix) cout << i << " ";
        // cout << "\n";
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                ans[i][j] = ((i * n + j - 1) < 0 ? 1 : prefix[i * n + j - 1]) 
                            * ((i * n + j + 1) >= m * n ? 1 : suffix[i * n + j + 1]) % modulo;
            }
        }
        return ans;
    }
};

// [[3,2,5],[6,4,3],[6,3,1]]
// [[68916659],[263909215]]