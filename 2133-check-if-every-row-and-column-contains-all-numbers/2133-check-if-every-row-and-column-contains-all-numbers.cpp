class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        auto n{matrix.size()};
        vector<int> bs(n+1);
        for (auto& i : matrix) {
            for (auto& j : i) {
                if (bs[j]) return false;
                bs[j] = true;
            }
            bs = vector<int>(n+1);
        }
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (bs[matrix[j][i]]) return false;
                bs[matrix[j][i]] = true;
            }
            bs = vector<int>(n+1);
        }
        return true;
    }
};