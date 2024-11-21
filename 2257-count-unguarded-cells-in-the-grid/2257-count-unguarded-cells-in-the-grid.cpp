class Solution {
public:
    // simulate the process
    // note: if you dont check for another guard, you end up TLE-ing because you check the same cell for each guard!
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m, vector<int>(n, 1));
        int ans = m * n - guards.size() - walls.size();
        for (auto& i : walls) {
            v[i[0]][i[1]] = -1;
        }
        for (auto& i : guards) {
            v[i[0]][i[1]] = -2;
        }
        int x;
        int y;
        for (auto& i : guards) {
            x = i[0] - 1;
            y = i[1];
            while (x >= 0 && v[x][y] >= 0) {
                if (v[x][y] == 1) {
                    v[x][y] = 0;
                    --ans;
                }
                --x;
            }
            x = i[0] + 1;
            while (x < v.size() && v[x][y] >= 0) {
                if (v[x][y] == 1) {
                    v[x][y] = 0;
                    --ans;
                }
                ++x;
            }
            x = i[0];
            y = i[1] - 1;
            while (y >= 0 && v[x][y] >= 0) {
                if (v[x][y] == 1) {
                    v[x][y] = 0;
                    --ans;
                }
                --y;
            }
            y = i[1] + 1;
            while (y < v[0].size() && v[x][y] >= 0) {
                if (v[x][y] == 1) {
                    v[x][y] = 0;
                    --ans;
                }
                ++y;
            }
        }
        // for (auto i : v) {
        //     for (auto j : i) cout << j << " ";
        //     cout << "\n";
        // }
        return ans;
    }

    void dfs(vector<vector<int>>& v, int& ans, vector<int>& i) {

    }
};
// 2
// 7
// [[1,5],[1,1],[1,6],[0,2]]
// [[0,6],[0,3],[0,5]]
// 4
// 6
// [[0,0],[1,1],[2,3]]
// [[0,1],[2,2],[1,4]]