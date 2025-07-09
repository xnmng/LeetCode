// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/solutions/6935977/better-to-optimal-o-n-o-1-space-in-o-n-time
class Solution {
public:
    // note: read below first!
    //
    // instead of computing all the gaps, storing them and then doing the sliding window,
    // we keep track of the total space and the total event time, then do math
    // (no need store anything)
    //
    // O(n) time, O(1) space
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int ans = 0;
        int start = 0;
        int total = 0;
        int blocked = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, startTime[i] - start - blocked);
            blocked += endTime[i] - startTime[i];
            if (i >= k) {
                start = endTime[i - k];
                blocked -= endTime[i - k] - startTime[i - k];
            }
        }
        ans = max(ans, eventTime - start - blocked);
        return ans;
    }

    // // if we shift k meetings, we can merge k+1 free time blocks
    // // sliding window on these k+1 free time blocks to find the ans
    // //
    // // O(n) time, O(n) space
    // int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    //     int n = startTime.size();
    //     vector<int> v;
    //     v.reserve(n + 1);
    //     int ans = 0;
    //     int prev = 0;
    //     for (int i = 0; i < n; ++i) {
    //         v.emplace_back(startTime[i] - prev);
    //         prev = endTime[i];
    //     }
    //     if (prev != eventTime) v.emplace_back(eventTime - endTime.back());
    //     int cur = 0;
    //     // for (int i : v) cout << i << " ";
    //     // cout << "\n";
    //     for (int i = 0; i < v.size(); ++i) {
    //         cur += v[i];
    //         ans = max(ans, cur);
    //         if (i >= k) cur -= v[i - k];
    //     }
    //     return ans;
    // }
};