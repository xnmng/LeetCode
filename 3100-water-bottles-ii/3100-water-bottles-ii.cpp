class Solution {
public:
    // just simulate the process
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            ++ans;
            // equivalent to just empty = empty - numExchange + 1;
            // empty -= numExchange;
            // ++empty;
            empty = empty - numExchange + 1;
            ++numExchange;
        }
        return ans;
    }
};