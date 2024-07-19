class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<int> minRow(matrix.size(), INT_MAX);
        vector<int> maxCol(matrix[0].size(), INT_MIN);
        for (auto i = 0; i < matrix.size(); ++i) {
            for (auto j = 0; j < matrix[0].size(); ++j) {
                minRow[i] = min(minRow[i], matrix[i][j]);
                maxCol[j] = max(maxCol[j], matrix[i][j]);
            }
        }
        unordered_set<int> s;
        for (auto& i : minRow) {
            s.insert(i);
            // cout << i << " ";
        }
        // cout << "\n";
        for (auto& i : maxCol) {
            // cout << i << " ";
            if (s.find(i) != s.end()) ans.push_back(i);
        }
        // cout << "\n";
        return ans;
    }
};