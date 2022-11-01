class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        ans.reserve(grid[0].size());        
        int x{0};
        int y{-1};
        for (auto i = 0; i < grid[0].size(); ++i) {
            x = 0;
            y = i;
            // cout << "\n";
            // cout << x << " " << y << "\n";
            while (x < grid.size()) {
                if (y == 0 && grid[x][y] == -1) break;
                // cout << "ok\n";
                if (y == grid[0].size()-1 && grid[x][y] == 1) break;
                if (y+1 < grid[0].size() && grid[x][y] == 1 && grid[x][y+1] == -1) break;
                if (y-1 >= 0 && grid[x][y-1] == 1 && grid[x][y] == -1) break;
                
                grid[x][y] == 1 ? ++y : --y;
                ++x;
                // cout << x << " " << y << "\n";
            }
            if (x == grid.size()) ans.push_back(y);
            else ans.push_back(-1);
        }
        return ans;
    }
};

/*
[ 1, 1, 1, 1, 1, 1],
[-1,-1,-1,-1,-1,-1],
[ 1, 1, 1, 1, 1, 1],
[-1,-1,-1,-1,-1,-1]
*/