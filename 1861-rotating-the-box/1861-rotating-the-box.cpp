class Solution {
public:
    // transpose the box, then move the obstacles down
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        int next;
        for (int i = 0; i < m; ++i) {
            next = n-1;
            for (int j = n-1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    ans[j][i] = '*';
                    next = j-1;
                }
                else if (box[i][j] == '#') {
                    ans[next][i] = '#';
                    --next;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};