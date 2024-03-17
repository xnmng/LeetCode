class Solution {
    // https://stackoverflow.com/questions/325933/determine-whether-two-date-ranges-overlap/325964#325964
    bool hasOverlap(vector<int>& v1, vector<int>& v2) {
        return v1[0] <= v2[1] && v2[0] <= v1[1];
    }
public:
    // since intervals is initially non-overlapping, we have 3 scenarios after inserting newInterval in order:
    // - newInterval does not overlap with any other interval
    // - newInterval overlaps with the interval before/after it (in sorted order)
    // - newInterval overlaps with both intervals before and after it (in sorted order)
    //
    // add intervals before, merge middle, add the end
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        // merge intervals before newInterval
        while (i < intervals.size() 
               && intervals[i][1] < newInterval[0]
               && !hasOverlap(intervals[i], newInterval)) {
            ans.push_back(intervals[i]);
            ++i;
        }
        // merge newInterval if needed, then add
        while (i < intervals.size() 
               && hasOverlap(intervals[i], newInterval)) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            ++i;
        }
        ans.push_back(newInterval);
        // add the rest of the intervals
        ans.insert(ans.end(), intervals.begin()+i, intervals.end());
        return ans;
    }
};

// [[1,5]]
// [0,0]
// []
// [5,7]