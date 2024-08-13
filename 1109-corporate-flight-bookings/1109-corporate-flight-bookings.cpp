class Solution {
public:
    // 1-based indexing; -1 accordingly
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> offset(n+1, 0);
        for (auto i : bookings) {
            offset[i[0]-1] += i[2];
            offset[i[1]] -= i[2];
        }
        vector<int> ans;
        ans.reserve(n-1);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += offset[i];
            ans.emplace_back(cur);
        }
        return ans;
    }
};