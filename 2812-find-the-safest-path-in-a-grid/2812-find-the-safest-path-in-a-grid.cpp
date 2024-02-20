class Solution {
    // note: DP DOES NOT WORK:
    // see:
    // https://leetcode.com/problems/find-the-safest-path-in-a-grid/discuss/3870053/BFS-+-Dijkstra/2002338
public:
    int maximumSafenessFactor(vector<vector<int>>& g) {
    queue<array<int, 2>> q;
    int dir[5] = {1, 0, -1, 0, 1}, n = g.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (g[i][j])
                q.push({i, j});
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (min(x, y) >= 0 && max(x, y) < n && g[x][y] == 0) {
                g[x][y] = g[i][j] + 1;
                q.push({x, y});
            }
        }
    }
    priority_queue<array<int, 3>> pq;
    pq.push({g[0][0], 0, 0});
    while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
        auto [sf, i, j] = pq.top(); pq.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (min(x, y) >= 0 && max(x, y) < n && g[x][y] > 0) {
                pq.push({min(sf, g[x][y]), x, y});
                g[x][y] *= -1; 
            }
        }
    }
    return pq.top()[0] - 1;
}
};
    // O(n^2log(n^2)) time, O(n^2) space
    // rewording the question:
    // (safeness definition stays the same)
    // find a path with safeness factor k such that there does not exist another path with psafeness GREATER than k
    // (i.e. for a given path, the psafeness of that path is the smallest safeness of any square)
//     bool valid(int x, int y, int n) {
//         return x >= 0 && x < n && y >= 0 && y < n;
//     }
    
//     int maximumSafenessFactor(vector<vector<int>>& grid) {
//         int n = grid.size();
        
//         // initialize this, then use it to find the answer
//         vector<vector<int>> safenessGrid(n, vector<int>(n, -1));
//         vector<vector<bool>> visited(n, vector<bool>(n, false));
//         queue<pair<int,int>> q;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] == 1) q.emplace(i, j);
//             }
//         }
//         vector<int> rdir{1,-1,0,0};
//         vector<int> cdir{0,0,1,-1};
//         int safeness = 0;
//         while (!q.empty()) {
//             queue<pair<int,int>> next;
//             while (!q.empty()) {
//                 auto [r, c] = q.front();
//                 q.pop();
//                 if (safenessGrid[r][c] != -1) continue;
//                 safenessGrid[r][c] = safeness;
//                 for (int i = 0; i < 4; ++i) {
//                     int nextr = r + rdir[i];
//                     int nextc = c + cdir[i];
//                     if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < n) {
//                         next.emplace(nextr, nextc);
//                     }
//                 }
//             }
//             ++safeness;
//             swap(next, q);
//         }
        
//         // cannot use vector<int> because it will TLE!
        
//         // if 2 cells have the same safeness factor, doesnt matter which one we process first
//         auto comp = [](pair<int,pair<int,int>> a, pair<int,pair<int,int>> b) {
//             return a.first < b.first;
//         };
        
//         // dijkstras to find answer (not sure what this means)
//         // use a pq and process largest value safeness grids first, until we find destination
//         priority_queue<pair<int,pair<int,int>>, 
//                         vector<pair<int,pair<int,int>>>, 
//                         decltype(comp)> pq(comp); // <safeness, x, y>
//         pq.push({safenessGrid[0][0], {0, 0}});
//         int ans = INT_MAX;
//         int curSafeness;
//         int x;
//         int y;
//         visited = vector<vector<bool>>(n, vector<bool>(n, false));
//         while(!pq.empty()) {
//             curSafeness = pq.top().first;                
//             x = pq.top().second.first;                
//             y = pq.top().second.second;                
//             pq.pop();
//             ans = min(ans, safenessGrid[x][y]);
//             if (x == n-1 && y == n-1) break;
//             visited[x][y] = true;
//             for (int i = 0; i < 4; ++i) {
//                 int nextx = x + rdir[i];
//                 int nexty = y + cdir[i];
//                 if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && !visited[nextx][nexty]) {
//                     pq.push({safenessGrid[nextx][nexty], {nextx, nexty}});
//                 }
//             }
//         }
        
//         return ans;
//     }
// };
// [[0,0],[0,1]]
// [[1]]

// // O(n^2 * logn) time, O(n^2) space - preprocess grid then binary search on it to find ans
// class Solution {
//     bool valid(int x, int y, int n) {
//         return x >= 0 && x < n && y >= 0 && y < n;
//     }
    
//     bool helper(vector<vector<int>>& grid, int val) {
//         // cout << "val=" << val << "\n";
//         int n = grid.size();
//         if (grid[0][0] < val) return false;
//         queue<pair<int,int>> q;
//         q.emplace(0, 0);
//         vector<vector<bool>> visited(n, vector<bool>(n, false));
//         vector<int> rdir{1,-1,0,0};
//         vector<int> cdir{0,0,1,-1};
//         while (!q.empty()) {
//             auto [r, c] = q.front();
//             q.pop();
//             if (visited[r][c]) continue;
//             visited[r][c] = true;
//             if (r == n-1 && c == n-1) return true;
//             for (int i = 0; i < 4; ++i) {
//                 int nextr = r + rdir[i];
//                 int nextc = c + cdir[i];
//                 // cout << nextr << " " << nextc << " " 
//                 //     << valid(nextr, nextc, n) << " " << (grid[nextr][nextc] >= val) << "\n";
//                 if (valid(nextr, nextc, n) && grid[nextr][nextc] >= val) {
//                     // cout << "add " << nextr << " " << nextc << "\n";
//                     q.emplace(nextr, nextc);
//                 }
//             }
//         }
//         // cout << "unable to find path with k == " << val << "\n";
//         return false;
//     }
// public:
//     int maximumSafenessFactor(vector<vector<int>>& grid) {
//         int n = grid.size();
//         // initialize this, then do binary search on it (bfs) to find the answer
//         vector<vector<int>> safenessGrid(n, vector<int>(n, -1));
//         vector<vector<bool>> visited(n, vector<bool>(n, -1));
//         queue<pair<int,int>> q;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] == 1) q.emplace(i, j);
//             }
//         }
//         vector<int> rdir{1,-1,0,0};
//         vector<int> cdir{0,0,1,-1};
//         int safeness = 0;
//         while (!q.empty()) {
//             queue<pair<int,int>> next;
//             while (!q.empty()) {
//                 auto [r, c] = q.front();
//                 q.pop();
//                 if (safenessGrid[r][c] != -1) continue;
//                 safenessGrid[r][c] = safeness;
//                 for (int i = 0; i < 4; ++i) {
//                     int nextr = r + rdir[i];
//                     int nextc = c + cdir[i];
//                     if (valid(nextr, nextc, n)) {
//                         next.emplace(nextr, nextc);
//                     }
//                 }
//             }
//             ++safeness;
//             swap(next, q);
//         }
        
//         // for (auto i : safenessGrid) {
//         //     for (auto j : i) cout << j << " ";
//         //     cout << "\n";
//         // }
        
//         // binary search to find answer
//         int ans = 0;
//         int left = 0;
//         int right = 2 * n;
//         int mid;
//         while (left <= right) {
//             mid = left + (right - left) / 2;
//             if (helper(safenessGrid, mid)) {
//                 // probably dont need to use max, 
//                 // since if ans=k is a valid solution
//                 // we will try for values > k in next iteration
//                 ans = max(ans, mid);
//                 left = mid+1;
//             } else {
//                 right = mid-1;
//             }
//         }
        
//         return ans;
//     }
// };