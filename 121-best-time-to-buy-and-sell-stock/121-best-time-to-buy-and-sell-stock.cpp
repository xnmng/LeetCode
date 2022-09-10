class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto ans{0};
        auto cur{prices[0]};
        for (auto i = 1; i < prices.size(); ++i) {
            cur = min(cur, prices[i]);
            ans = max(ans, prices[i] - cur);
        }
        return ans;
    }
};