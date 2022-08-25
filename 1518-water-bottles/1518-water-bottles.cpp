class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        auto ans{numBottles};
        auto empty{numBottles};
        while (empty >= numExchange) {
            ans += empty / numExchange;
            empty = empty % numExchange + empty / numExchange;
        }
        return ans;
    }
};