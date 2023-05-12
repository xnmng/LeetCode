class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), 0);
        auto ans{0ll};
        for (auto i = static_cast<int>(questions.size()-1); i >= 0; --i) {
            if (i + questions[i][1] + 1 < questions.size()) {
                dp[i] += dp[i + questions[i][1] + 1];
            }
            dp[i] += questions[i][0];
            dp[i] = max(dp[i], ans);
            ans = dp[i];
        }
        return ans;
    }
};

// [[21,5],[92,3],[74,2],[39,4],[58,2],[5,5],[49,4],[65,3]]