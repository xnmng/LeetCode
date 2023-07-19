// https://leetcode.com/problems/non-overlapping-intervals/solution/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals according to the end times
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        auto prev{INT_MIN};
        auto ans{0};
        for (auto& i : intervals) {
            // overlap; need to greedily remove one interval
            if (prev > i[0]) ++ans;
            else prev = i[1];
        }
        return ans;
    }
};
// [[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]]