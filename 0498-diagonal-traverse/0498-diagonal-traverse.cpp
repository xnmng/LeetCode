class Solution {
public:
    // diagonal traverse then reverse
    // O(mn), O(mn) space (temp)
    // vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    //     vector<int> ans;
    //     int m = mat.size();
    //     int n = mat[0].size();
    //     ans.reserve(m * n);
    //     for (int i = 0; i < m; ++i) {

    //     }
    // }

    // simulation
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        ans.reserve(m * n);
        bool topright = true;
        int x = 0;
        int y = 0;
        for (int i = 0; i < m * n; ++i) {
            // cout << x << " " << y << " " << topright << "\n";
            // cout << "added " << mat[x][y] << "\n"; 
            ans.emplace_back(mat[x][y]);
            if (topright) {
                if (y == n-1 || x == 0) {
                    topright = false;
                    // default next row is right, unless OOB then down
                    if (y + 1 == n) {
                        ++x;
                    }
                    else {
                        ++y;
                    }
                }
                else {
                    --x;
                    ++y;
                }
            }
            else {
                if (y == 0 || x == m-1) {
                    topright = true;
                    // by default next row is bottom unless OOB, then right
                    if (x + 1 == m) {
                        ++y;
                    }
                    else {
                        ++x;
                    }
                }
                else {
                    ++x;
                    --y;
                }
            }
        }
        return ans;
    }
};