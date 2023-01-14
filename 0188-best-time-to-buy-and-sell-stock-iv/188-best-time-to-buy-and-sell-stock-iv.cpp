// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/188630/C++-Top-Down-and-Bottom-Up-DP
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        auto ans{0};
        if (k > prices.size()/2) {
            for (auto i = 1; i < prices.size(); ++i) {
                ans += max(0, prices[i] - prices[i-1]);
            }
            return ans;
        }
        
        vector<int> buy(k+1, INT_MIN);
        vector<int> sell(k+1, 0);
        for (auto i : prices) {
            for (auto j = 1; j < sell.size(); ++j) {
                buy[j] = max(buy[j], sell[j-1] - i);
                sell[j] = max(sell[j], buy[j] + i);
            }
        }
        return sell[k];
    }
};

// 2
// [1,2,4]
// 2
// [6,1,3,2,4,7]