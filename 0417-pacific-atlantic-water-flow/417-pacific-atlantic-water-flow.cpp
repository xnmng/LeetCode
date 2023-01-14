class Solution {
    void dfs(vector<vector<int>>& arr, int i, int j, vector<vector<int>>& visited) {
        ++visited[i][j];
        
        if (i+1 < arr.size() 
            && visited[i+1][j] == 0 
            && arr[i][j] <= arr[i+1][j]) dfs(arr, i+1, j, visited);
        if (i-1 >= 0 
            && visited[i-1][j] == 0 
            && arr[i][j] <= arr[i-1][j]) dfs(arr, i-1, j, visited);
        if (j+1 < arr[0].size() 
            && visited[i][j+1] == 0 
            && arr[i][j] <= arr[i][j+1]) dfs(arr, i, j+1, visited);
        if (j-1 >= 0 
            && visited[i][j-1] == 0 
            && arr[i][j] <= arr[i][j-1]) dfs(arr, i, j-1, visited);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        auto m{arr.size()};
        auto n{arr[0].size()};
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        
        for (auto i = 0; i < n; ++i) {
            dfs(arr, 0, i, pacific);
            dfs(arr, m-1, i, atlantic);
        }
        for (auto i = 0; i < m; ++i) {
            dfs(arr, i, 0, pacific);
            dfs(arr, i, n-1, atlantic);
        }
        
        vector<vector<int>> ans;
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};