class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans(2, vector<int>(colsum.size(), 0));
        for (auto i = 0; i < colsum.size(); ++i) {
            if (colsum[i] == 2) {
                if (upper == 0 || lower == 0) return {};
                ans[0][i] = 1;
                ans[1][i] = 1;
                --upper;
                --lower;
            }
            else if (colsum[i] == 1) {
                if (upper == 0 && lower == 0) return {};
                if (upper > lower) {
                    ans[0][i] = 1;
                    --upper;
                } else {
                    ans[1][i] = 1;
                    --lower;
                }
            }
        }
        if (upper == 0 && lower == 0) return ans;
        return {};
    }
};

// 4
// 7
// [2,1,2,2,1,1,1]