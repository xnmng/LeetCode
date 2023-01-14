class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        auto ans{0};
        for (auto i : costs) {
            if (coins >= i) {
                coins -= i;
                ++ans;
            }
            else break;
        }
        return ans;
    }
};