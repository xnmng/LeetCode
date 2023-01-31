// https://youtu.be/7kURH3btcV4
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v; // (score, age)
        auto n{scores.size()};
        for (auto i = 0; i < n; ++i) {
            v.emplace_back(scores[i], ages[i]);
        }
        sort(v.begin(), v.end());
        vector<int> dp(n);
        for (auto i = 0; i < n; ++i) dp[i] = v[i].first;
        auto ans{0};
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < i; ++j) {
                if (v[i].second >= v[j].second) dp[i] = max(dp[i], v[i].first + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// [319776,611683,835240,602298,430007,574,142444,858606,734364,896074]
// [1,1,1,1,1,1,1,1,1,1]