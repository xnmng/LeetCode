class Solution {
public:
    // dfs would work
    //
    // TODO: solve using union find disjoint set
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        unordered_map<int,vector<int>> cols; // coordinate to index (stones[i])
        unordered_map<int,vector<int>> rows; // coordinate to index (stones[i])
        
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i) {
            // cout << "pre " << stones[i][0] << " " << stones[i][1] << "\n";
            // cout << "col " << stones[i][1] << " add " << i << "\n";
            // cout << "row " << stones[i][0] << " add " << i << "\n";
            rows[stones[i][0]].emplace_back(i);
            cols[stones[i][1]].emplace_back(i);
        }
        
        int count = 0; // number of components
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // cout << "dfs " << i << "\n";
                dfs(i, stones, cols, rows, visited);
                ++count;
            }
        }
        
        return n - count;
    }
    
    void dfs(int index, vector<vector<int>>& stones,
             unordered_map<int, vector<int>>& cols, 
             unordered_map<int, vector<int>>& rows, 
             vector<bool>& visited) {
        // cout << "at " << stones[index][0] << " " << stones[index][1] << "\n";
        if (!visited[index]) {
            visited[index] = true;
            for (int i : rows[stones[index][0]]) {
                if (!visited[i]) dfs(i, stones, cols, rows, visited);
            }
            for (int i : cols[stones[index][1]]) {
                if (!visited[i]) dfs(i, stones, cols, rows, visited);
            }

        }
    }
};
// [[0,1],[1,2],[1,3],[3,3],[2,3],[0,2]]
// [[0,1],[1,0]]