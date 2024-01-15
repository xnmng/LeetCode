class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int repeated;
        unordered_set<int> s;
        int n = pow(grid.size(),2);
        int missing = n * (n+1) / 2;
        for (auto i : grid) {
            for (auto j : i) {
                if (!s.insert(j).second) {
                    repeated = j;
                } else {
                    missing -= j;
                }                
            }
        }
        return {repeated, missing};
    }
};