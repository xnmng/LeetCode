class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        auto left{0};
        auto right{n-1};
        auto up{0};
        auto down{n-1};
        auto dir{0};
        auto count{1};
        while (left <= right && up <= down) {
            if (dir == 0) {
                for (auto i = left; i <= right; ++i) {
                    ans[up][i] = count;
                    ++count;
                }
                ++up;
            }
            else if (dir == 1) {
                for (auto i = up; i <= down; ++i) {
                    ans[i][right] = count;
                    ++count;
                }
                --right;
            }
            else if (dir == 2) {
                for (auto i = right; i >= left; --i) {
                    ans[down][i] = count;
                    ++count;
                }
                --down;
            }
            else if (dir == 3) {
                for (auto i = down; i >= up; --i) {
                    ans[i][left] = count;
                    ++count;
                }
                ++left;
            }
            
            dir = (dir+1) % 4;
        }
        return ans;
    }
};