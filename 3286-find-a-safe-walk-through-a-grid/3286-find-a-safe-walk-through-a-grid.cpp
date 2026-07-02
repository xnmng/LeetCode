struct s {
    int x, y, h;
};

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<s> q;
        q.push(s(0, 0, health - grid[0][0]));
        vector<vector<int>> v(m, vector<int>(n, -1));
        v[0][0] = health - grid[0][0];
        
        while (!q.empty()) {
            s cur = q.front();
            q.pop();
            
            int x = cur.x, y = cur.y, h = cur.h;
            if (x == m - 1 && y == n - 1 && h > 0) {
                // cout << h << "\n";
                return true;
            }
            
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int nh = h - grid[nx][ny];
                    if (nh > 0 && nh > v[nx][ny]) {
                        v[nx][ny] = nh;
                        q.push(s(nx, ny, nh));
                    }
                }
            }
        }
        
        return false;
    }
};
// [[1,1,1,1]]