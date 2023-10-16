class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex <= 1) return vector<int>(rowIndex+1, 1);
        vector<int> ans{1, 1};
        vector<int> next;
        for (int i = 2; i <= rowIndex; ++i) {
            next = vector<int>(ans.size()+1, 1);
            for (auto j = 0; j < ans.size()-1; ++j) {
                next[j+1] = ans[j] + ans[j+1];
            }
            swap(ans, next);
        }
        return ans;
    }
};