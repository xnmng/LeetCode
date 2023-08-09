class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for (int i = 0; i < times.size(); ++i) {
            times[i].emplace_back(i);
        }
        // times[i] = (arrival time, leaving time, friend no.)
        sort(times.begin(), times.end());
        priority_queue<
            pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>> pq; // (leaving time, seat occupied)
        int next{0}; // next available seat if all seats are full
        priority_queue<int, vector<int>, greater<int>> seat; // stores seats
        int ans;
        for (int i = 0; i < times.size(); ++i) {
            int arrival{times[i][0]};
            int leaving{times[i][1]};
            int curFriend{times[i][2]};
            while (!pq.empty() && pq.top().first <= arrival) {
                seat.push(pq.top().second);
                pq.pop();
            }
            if (curFriend == targetFriend) {
                ans = seat.empty() ? next : seat.top();
                break;
            }
            if (seat.empty()) {
                pq.emplace(leaving, next);
                ++next;
            } else {
                pq.emplace(leaving, seat.top());
                seat.pop();
            }
        }
        return ans;
    }
};
// [[33889,98676],[80071,89737],[44118,52565],[52992,84310],[78492,88209],[21695,67063],[84622,95452],[98048,98856],[98411,99433],[55333,56548],[65375,88566],[55011,62821],[48548,48656],[87396,94825],[55273,81868],[75629,91467]]
// 6