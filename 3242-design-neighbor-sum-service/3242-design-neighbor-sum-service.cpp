class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int adjSum;
        int diagSum;
        mp.reserve(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                adjSum = 0;
                diagSum = 0;
                if (valid(i+1, j, m, n)) adjSum += grid[i+1][j];
                if (valid(i-1, j, m, n)) adjSum += grid[i-1][j];
                if (valid(i, j+1, m, n)) adjSum += grid[i][j+1];
                if (valid(i, j-1, m, n)) adjSum += grid[i][j-1];
                if (valid(i+1, j+1, m, n)) diagSum += grid[i+1][j+1];
                if (valid(i+1, j-1, m, n)) diagSum += grid[i+1][j-1];
                if (valid(i-1, j+1, m, n)) diagSum += grid[i-1][j+1];
                if (valid(i-1, j-1, m, n)) diagSum += grid[i-1][j-1];
                mp.insert({grid[i][j], {adjSum, diagSum}});
            }
        }
    }
    
    int adjacentSum(int value) {        
        return mp[value].first;
    }
    
    int diagonalSum(int value) {
        return mp[value].second;
    }
private:
    unordered_map<int,pair<int,int>> mp; // value -> <adjSum, diagSum>
    
    bool valid(int i, int j, int m, int n) {
        return i < m && i >= 0 && j < n && j >= 0;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */