class Solution {
    bool valid(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    
    bool helper(vector<vector<int>>& grid, int val) {
        // cout << "val=" << val << "\n";
        int n = grid.size();
        if (grid[0][0] < val) return false;
        queue<pair<int,int>> q;
        q.emplace(0, 0);
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<int> rdir{1,-1,0,0};
        vector<int> cdir{0,0,1,-1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (visited[r][c]) continue;
            visited[r][c] = true;
            if (r == n-1 && c == n-1) return true;
            for (int i = 0; i < 4; ++i) {
                int nextr = r + rdir[i];
                int nextc = c + cdir[i];
                // cout << nextr << " " << nextc << " " 
                //     << valid(nextr, nextc, n) << " " << (grid[nextr][nextc] >= val) << "\n";
                if (valid(nextr, nextc, n) && grid[nextr][nextc] >= val) {
                    // cout << "add " << nextr << " " << nextc << "\n";
                    q.emplace(nextr, nextc);
                }
            }
        }
        // cout << "unable to find path with k == " << val << "\n";
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        // initialize this, then do binary search on it (bfs) to find the answer
        vector<vector<int>> safenessGrid(n, vector<int>(n, -1));
        vector<vector<bool>> visited(n, vector<bool>(n, -1));
        queue<pair<int,int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) q.emplace(i, j);
            }
        }
        vector<int> rdir{1,-1,0,0};
        vector<int> cdir{0,0,1,-1};
        int safeness = 0;
        while (!q.empty()) {
            queue<pair<int,int>> next;
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                if (safenessGrid[r][c] != -1) continue;
                safenessGrid[r][c] = safeness;
                for (auto i = 0; i < 4; ++i) {
                    int nextr = r + rdir[i];
                    int nextc = c + cdir[i];
                    if (valid(nextr, nextc, n)) {
                        next.emplace(nextr, nextc);
                    }
                }
            }
            ++safeness;
            swap(next, q);
        }
        
        // for (auto i : safenessGrid) {
        //     for (auto j : i) cout << j << " ";
        //     cout << "\n";
        // }
        
        // binary search to find answer
        int ans = 0;
        int left = 0;
        int right = 2 * n;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (helper(safenessGrid, mid)) {
                // probably dont need to use max, 
                // since if ans=k is a valid solution
                // we will try for values > k in next iteration
                ans = max(ans, mid);
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        return ans;
    }
};