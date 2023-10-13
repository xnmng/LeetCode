class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prevprev = cost[0];
        int prev = cost[1];
        int temp;
        for (auto i = 2; i < cost.size(); ++i) {
            temp = cost[i] + min(prevprev, prev);
            prevprev = prev;
            prev = temp;
        }
        return min(prevprev, prev);
    }
};
