// probably faster if we did bottom-up DP (?)

// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/solution/
class Solution {
private:
    // at each index, either skip the event, 
    // or pick the event, gaining events[index][2] value
    // the next event one can attend (index) is found using binary search
    
    // suppose we select an event at index i to attend 
    // the next index we can attend after i, j, is fixed (does not change)
    // thus we can cache it as well (memoization idea from DP approach)
    int dfs(int index, int k, vector<vector<int>>& events, vector<vector<int>>& dp, vector<int>& dpNextIndex) {
        if (dp[index][k] == INT_MIN) {
            if (k == 0 || index == events.size()) {
                dp[index][k] = 0;
            } else {
                dp[index][k] = max(
                    events[index][2] + dfs(dpNextIndex[index], k-1, events, dp, dpNextIndex), 
                    dfs(index+1, k, events, dp, dpNextIndex));
            }
        }
        return dp[index][k];
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // sort events by start time
        sort(events.begin(), events.end(), 
            [](vector<int> a, vector<int> b) {
                if (a[0] == b[0]) return a[2] < b[2];
                return a[0] < b[0];     
            }
        );
        vector<vector<int>> dp(events.size()+1, vector<int>(k+1, INT_MIN));
        vector<int> dpNextIndex(events.size()+1, INT_MIN);
        vector<int> target;
        for (auto i = 0; i < events.size(); ++i) {
            target = {events[i][1], INT_MAX, INT_MAX};
            dpNextIndex[i] = upper_bound(events.begin()+i+1, events.end(), target) 
                        - events.begin();
        }
        return dfs(0, k, events, dp, dpNextIndex);
    }
};