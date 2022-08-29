class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        auto isOdd{mat.size() % 2 == 1};
        auto ans{0};
        auto n{mat.size()};
        for (auto i = 0; i < n; ++i) {
            // cout << i << " " << n-1-i << "\n";
            ans += mat[i][i];
            if (isOdd && i == n-1-i) {
                continue;
            }
            ans += mat[i][n-1-i];
        }
        
        return ans;
    }
};