class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto ans{0};
        auto cur{prices[0]};
        for (auto i = 1; i < prices.size(); ++i) {
            if (cur > prices[i]) {
                cur = prices[i];
            } else {
                ans = max(ans, prices[i] - cur);
            }
        }
        return ans;
    }
};