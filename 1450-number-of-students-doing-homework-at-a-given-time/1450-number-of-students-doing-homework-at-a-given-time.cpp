class Solution {
public:
    // trivial; just scan and check
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        int n = startTime.size();
        for (int i = 0; i < n; ++i) {
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
                ++ans;
            }
        }
        return ans;
    }
};