class Solution {
public:
    // we dont care about yi, only xi
    // get all unique xi, sort, find minimum number of rectangles needed greedily
    //
    // O(nlogn) time, O(1) space
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int prev = INT_MIN;
        int ans = 0;
        for (auto i : points) {
            if (w + prev >= i[0]) continue;
            prev = i[0];
            ++ans;
        }
        return ans;
    }
    
    // O(nlogn) time, O(n) space
    // int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
    //     set<int> s;
    //     for (auto i : points) {
    //         s.insert(i[0]);
    //     }
    //     int prev = INT_MIN;
    //     int ans = 0;
    //     for (auto i : s) {
    //         if (w + prev >= i) continue;
    //         prev = i;
    //         ++ans;
    //     }
    //     return ans;
    // }
};