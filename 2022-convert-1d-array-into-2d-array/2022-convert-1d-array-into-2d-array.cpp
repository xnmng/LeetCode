class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return {};
        vector<vector<int>> ans(m, vector<int>(n, 0));
        int x = 0;
        int y = 0;
        for (int i : original) {
            ans[x][y] = i;
            ++y;
            if (y == n) {
                ++x;
                y = 0;
            }
        }
        return ans;
    }
};