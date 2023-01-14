// https://stackoverflow.com/questions/3269434/whats-the-most-efficient-way-to-test-if-two-ranges-overlap
class Solution {
private:
    bool intersect(vector<int>& v, int start, int end) {
        return max(start, v[0]) <= min(end, v[1]);
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto ans{1};
        sort(points.begin(), points.end());
        auto start{points[0][0]};
        auto end{points[0][1]};
        for (auto i = 1; i < points.size(); ++i) {
            if (intersect(points[i], start, end)) {
                start = max(start, points[i][0]);
                end = min(end, points[i][1]);
            } else {
                ++ans;
                start = points[i][0];
                end = points[i][1];
            }
        }
        return ans;
    }
};