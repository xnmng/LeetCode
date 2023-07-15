class Solution {
private:
    // at each index, either skip the event, 
    // or pick the event, gaining events[index][2] value
    // the next event one can attend (index) is found using binary search 
    int dfs(int index, int k, vector<vector<int>>& events, vector<vector<int>>& dp) {
        if (dp[index][k] == INT_MIN) {
            if (k == 0 || index == events.size()) {
                dp[index][k] = 0;
            } else {
                vector<int> target{events[index][1], INT_MAX, INT_MAX};
                auto nextIndex{
                    upper_bound(events.begin()+index+1, events.end(), target)
                    - events.begin()};
                dp[index][k] = max(
                    events[index][2] + dfs(nextIndex, k-1, events, dp), 
                    dfs(index+1, k, events, dp));
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
        return dfs(0, k, events, dp);
    }
};