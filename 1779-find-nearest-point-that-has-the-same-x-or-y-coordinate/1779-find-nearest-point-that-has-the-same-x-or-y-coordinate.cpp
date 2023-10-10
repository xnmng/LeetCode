class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int dist = INT_MAX;
        for (auto i = 0; i < points.size(); ++i) {
            if ((x == points[i][0] || y == points[i][1]) 
                && abs(x - points[i][0]) + abs(y - points[i][1]) < dist) {
                dist = abs(x - points[i][0]) + abs(y - points[i][1]);
                ans = i;
            }
        }
        return ans;
    }
};