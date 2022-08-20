class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        auto ans{0};
        auto maxDistance{startFuel};
        priority_queue<int> pq;
        auto index{0};
        while (index < stations.size() && maxDistance >= stations[index][0]) {
            pq.push(stations[index][1]);
            ++index;
        }
        
        while (!pq.empty() && maxDistance < target) {
            ++ans;
            maxDistance += pq.top();
            pq.pop();
            while (index < stations.size() && maxDistance >= stations[index][0]) {
                pq.push(stations[index][1]);
                ++index;
            }
        }
        return maxDistance >= target ? ans : -1;
    }
};