class Solution {
public:
    // suppose today i want to sell the stock, how much would i make?
    // store the smallest price encountered so far, then calculate
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