class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans{-1, -1};
        int count;
        for (auto i = 0; i < mat.size(); ++i) {
            count = 0;
            for (auto& j : mat[i]) {
                if (j == 1) ++count;
            }
            if (count > ans[1]) {
                ans[0] = i;
                ans[1] = count;
            }
        }
        return ans;
    }
};