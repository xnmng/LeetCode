class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int ans;
        for (auto i = 0; i < grid.size(); ++i) {
            bool flag = true; // strongest
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (j == i) continue;
                if (grid[i][j] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};