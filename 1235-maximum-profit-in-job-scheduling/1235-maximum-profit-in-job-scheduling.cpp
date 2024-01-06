// https://youtu.be/3kU7VYcmffU
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409009/JavaC++Python-DP-Solution
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        int n{static_cast<int>(profit.size())};
        v.reserve(n);
        for (auto i = 0; i < n; ++i) {
            v.push_back({endTime[i], startTime[i], profit[i]}); // sort by end time!
            // cout << v.back().first.first << " " << v.back().first.second << " " << v.back().second << "\n";
        }
        sort(v.begin(), v.end());
        // for (auto i : v) {
        //     cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
        // }
        map<int,int> dp{{0,0}};
        int val;
        for (auto i = 0; i < n; ++i) {
            // cout << (upper_bound(dp.begin(), dp.end(), v[i].first)-1)->first << " " << (upper_bound(dp.begin(), dp.end(), v[i].first)-1)->second << "\n";
            val = prev(dp.upper_bound(v[i][1]))->second + v[i][2];
            if (val > dp.rbegin()->second) {
                dp[v[i][0]] = val;
            }
        }
        // for (auto i : dp) {
        //     cout << i.first << " " << i.second << "\n";
        // }
        // cout << "\n";
        return dp.rbegin()->second;
    }
};