class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        auto left{0};
        auto right{static_cast<int>(matrix[0].size()-1)};
        auto up{0};
        auto down{static_cast<int>(matrix.size()-1)};
        auto dir{0};
        vector<int> ans;
        while (left <= right && up <= down) {
            if (dir == 0) {
                for (auto i = left; i <= right; ++i) {
                    ans.push_back(matrix[up][i]);
                }
                ++up;
            }
            else if (dir == 1) {
                for (auto i = up; i <= down; ++i) {
                    ans.push_back(matrix[i][right]);
                }
                --right;
            }
            else if (dir == 2) {
                for (auto i = right; i >= left; --i) {
                    ans.push_back(matrix[down][i]);
                }
                --down;
            }
            else if (dir == 3) {
                for (auto i = down; i >= up; --i) {
                    ans.push_back(matrix[i][left]);
                }
                ++left;
            }
            
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};