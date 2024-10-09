class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0; // number of fresh oranges
        queue<pair<int,int>> q;
        queue<pair<int,int>> next;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) ++count;                
                else if (grid[i][j] == 2) q.emplace(i, j);
            }
        }
        
        int ans = 0;
        while (!q.empty()) {
            while (!q.empty()) {
                auto [x,y] = q.front();
                q.pop();
                if (grid[x][y] == 1) --count;
                grid[x][y] = 2;
                if (x+1 < m && grid[x+1][y] == 1) next.emplace(x+1, y);
                if (y+1 < n && grid[x][y+1] == 1) next.emplace(x, y+1);
                if (x-1 >= 0 && grid[x-1][y] == 1) next.emplace(x-1, y);
                if (y-1 >= 0 && grid[x][y-1] == 1) next.emplace(x, y-1);
            }
            // for (auto i : grid) {
            //     for (auto j : i) cout << j << " ";
            //     cout << "\n";
            // }
            // cout << "\n";
            if (!next.empty() && count > 0) {
                // to account for initial state, we only increment ans only if we have a next state
                ++ans;
                swap(q, next);
            }
        }
        
        return count == 0 ? ans : -1;
    }
};
// [[2,2],[1,1],[0,0],[2,0]]