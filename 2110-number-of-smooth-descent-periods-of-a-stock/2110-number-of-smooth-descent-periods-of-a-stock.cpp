class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans{static_cast<long long>(prices.size())};
        auto index{1};
        auto count{0};
        while (index < prices.size()) {
            if (prices[index-1] - 1 == prices[index]) {
                ++count;
                ans += count;
            } else {
                count = 0;   
            }
            ++index;
        }
        return ans;
    }
};