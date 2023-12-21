class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> s;
        for (auto point : points) {
            s.insert(point[0]);
        }
        int prev = INT_MAX;
        int ans = 0;
        for (auto i : s) {
            ans = max(ans, i - prev);
            prev = i;
        }
        return ans;
    }
};