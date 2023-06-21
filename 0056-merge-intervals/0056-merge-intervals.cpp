class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        auto left{intervals[0][0]};
        auto right{intervals[0][1]};
        for (auto i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= right) right = max(right, intervals[i][1]);
            else {
                ans.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};
// [[1,4],[2,3]]