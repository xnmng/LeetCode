class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0 || grid.back().back() != 0) return -1;
        auto n{grid.size()};
        auto count{1};
        queue<pair<int,int>> q;
        queue<pair<int,int>> next;
        q.emplace(0, 0);
        while (!q.empty()) {
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                // cout << x << " " << y << "\n";
                if (x == n-1 && y == n-1) return count;
                if (grid[x][y] == -1) continue;
                grid[x][y] = -1;
                if (x+1 < n && grid[x+1][y] == 0) next.emplace(x+1, y);
                if (x-1 >= 0 && grid[x-1][y] == 0) next.emplace(x-1, y);
                if (x+1 < n && y+1 < n && grid[x+1][y+1] == 0) next.emplace(x+1, y+1);
                if (x-1 >= 0 && y+1 < n && grid[x-1][y+1] == 0) next.emplace(x-1, y+1);
                if (x+1 < n && y-1 >= 0 && grid[x+1][y-1] == 0) next.emplace(x+1, y-1);
                if (x-1 >= 0 && y-1 >= 0 && grid[x-1][y-1] == 0) next.emplace(x-1, y-1);
                if (y+1 < n && grid[x][y+1] == 0) next.emplace(x, y+1);
                if (y-1 >= 0 && grid[x][y-1] == 0) next.emplace(x, y-1);
            }
            swap(q, next);
            ++count;
        }
        return -1;
    }
};