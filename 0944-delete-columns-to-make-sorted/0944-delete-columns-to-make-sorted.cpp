class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        auto ans{0};
        auto m{strs.size()};
        auto n{strs[0].size()};
        for (auto j = 0; j < n; ++j) {
            for (auto i = 1; i < m; ++i) {
                if (strs[i][j] < strs[i-1][j]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};