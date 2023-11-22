class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        vector<pair<int,int>> temp;
        int m = nums.size();
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < nums[i].size(); ++j) {
                temp.emplace_back(i, j);
            }
        }
        // elements belonging to the same diagonal will have the same sum x+y
        // where coordinates are (x,y)
        // if they have the same diagonal sum, sort by who's x value is larger
        sort(temp.begin(), temp.end(), 
             [](pair<int,int> a, pair<int,int> b) {
                 if (a.first + a.second == b.first + b.second) {
                     return a.first > b.first;
                 }
                 else {
                     return (a.first + a.second < b.first + b.second);
                 }
            });
        for (auto& [x, y] : temp) {
            ans.emplace_back(nums[x][y]);
        }
        return ans;
    }
};
// [[11,6,9,20],[16,1,20],[14,19,14,17,15],[8,19,11,3],[3,13,17,4]]