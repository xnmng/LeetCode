class Solution {
public:
    // question constraints:
    // each farmland is rectangular in shape
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m = land.size();
        int n = land[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 1) {
                    vector<int> v{i, j, i, j};
                    dfs(land, i, j, v);
                    ans.emplace_back(move(v));
                }
            }
        }
        return ans;
    }
    
    // v = {min_x, min_y, max_x, max_y}
    void dfs(vector<vector<int>>& land, int i, int j, vector<int>& v) {
        v[0] = min(v[0], i);
        v[1] = min(v[1], j);
        v[2] = max(v[2], i);
        v[3] = max(v[3], j);
        land[i][j] = 0;
        if (i + 1 < land.size() && land[i + 1][j] == 1) dfs(land, i + 1, j, v);
        if (j + 1 < land[0].size() && land[i][j + 1] == 1) dfs(land, i, j + 1, v);
        if (i - 1 >= 0 && land[i - 1][j] == 1) dfs(land, i - 1, j, v);
        if (j - 1 >= 0 && land[i][j - 1] == 1) dfs(land, i, j - 1, v);
    }
};