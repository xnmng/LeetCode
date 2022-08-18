class Solution {
    bool hasOverlap(vector<int>& v1, vector<int>& v2) {
        return v1[0] <= v2[1] && v2[0] <= v1[1];
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        auto i{0};
        while (i < intervals.size() 
               && intervals[i][1] < newInterval[0]
               && !hasOverlap(intervals[i], newInterval)) {
            ans.push_back(intervals[i]);
            ++i;
        }
        while (i < intervals.size() 
               && hasOverlap(intervals[i], newInterval)) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            ++i;
        }
        ans.push_back(newInterval);
        ans.insert(ans.end(), intervals.begin()+i, intervals.end());
        return ans;
    }
};

// [[1,5]]
// [0,0]
// []
// [5,7]