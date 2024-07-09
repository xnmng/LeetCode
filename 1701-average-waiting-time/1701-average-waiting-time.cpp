class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long total = 0;
        int prev = 0;
        for (auto& i : customers) {
            if (prev > i[0]) {
                total += prev - i[0];
            }
            total += i[1];
            prev = max(prev + i[1], i[0] + i[1]);
        }
        return (double) total / customers.size();
    }
};