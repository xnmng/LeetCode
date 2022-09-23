class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto ans{intervals.size()};
        sort(intervals.begin(), intervals.end(), 
            [](vector<int> a, vector<int> b) {
                if (a[0] == b[0]) return a > b;
                return a < b;
            }
        );
        // for (auto i : intervals) {
        //     cout << i[0] << " " << i[1] << "\n";
        // }
        auto a{intervals[0][0]};
        auto b{intervals[0][1]};
        for (auto i = 1; i < intervals.size(); ++i) {
            // cout << a << " " << b << "\n";
            if (a <= intervals[i][0] && intervals[i][1] <= b) {
                --ans;
            } else {
                a = intervals[i][0];
                b = intervals[i][1];
            }
        }
        return ans;
    }
};

// sort by first value, if same, sort by largest second value 
// (to get larger interval in front of smaller interval with same first value)
// [[1,2],[1,4],[3,4]]
// [[1,2],[1,3]]
// [[1,3],[1,8],[5,8]]
// [[1,6],[4,6],[4,8]]