class Solution {
public:
    // observation: the rows that form the answer have the same "symmetry"
    // e.g. 001 and 110 are the same, but 101 and 010 are not the same
    // (2 majority elements and in the same position)
    // count the max freq of majority element and fix it, use ump to count
    
    // since m and n <= 300, cant use number and bitset, use string with '0' and '1'
    // for simplicity, fix first element to be '0'
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> mp;
        int ans = 0;
        string temp;
        temp.reserve(n);
        bool flip;
        for (int i = 0; i < m; ++i) {
            temp.clear();
            flip = (*matrix[i].begin() == 1);
            for (int j = 0; j < n; ++j) {
                if (flip) {
                    temp += '0' + (matrix[i][j] + 1) % 2;
                } else {
                    temp += '0' + matrix[i][j];
                }
            }
            ++mp[temp];
            ans = max(ans, mp[temp]);
            
        }
        return ans;
    }
};