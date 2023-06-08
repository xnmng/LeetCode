// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/solution/
class Solution {
    // if the ith row has the first negative element at index x 
    // then the first negative for (i + 1)th row can never be at indices greater than x
public:
    int countNegatives(vector<vector<int>>& grid) {
        auto ans{0};
        auto n{grid[0].size()};
        auto index{n-1};
        for (auto i = 0; i < grid.size(); ++i) {
            while (index != 0 && grid[i][index-1] < 0) {
                --index;
            }
            if (grid[i][index] < 0) ans += n - index;
        }
        return ans;
    }
};