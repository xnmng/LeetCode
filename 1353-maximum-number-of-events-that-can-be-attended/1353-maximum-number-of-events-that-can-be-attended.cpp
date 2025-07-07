class Solution {
public:
    // greedily add events to pq, pop the event in the pq with the earliest end day
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        int day = 1;
        int n = events.size();
        int cur = 0;
        while (cur < n) {
            if (pq.empty()) {
                day = events[cur][0];
                pq.emplace(events[cur][1]);
                // cout << "a: add [" << events[cur][0] << "," << events[cur][1]  << "]\n";
                ++cur;
            }
            while (cur < n && events[cur][0] <= day) {
                pq.emplace(events[cur][1]);
                // cout << "b: add [" << events[cur][0] << "," << events[cur][1]  << "]\n";
                ++cur;
            }
            if (!pq.empty() && pq.top() >= day) {
                ++ans;
                ++day;
                // cout << "attend " << pq.top() << "\n";
                pq.pop();
            }
            while (!pq.empty() && day > pq.top()) {
                // cout << "remove " << pq.top() << "\n";
                pq.pop();
            }
        }

        // handle remaining tasks
        while (!pq.empty()) {
            if (pq.top() >= day) {
                ++ans;
                ++day;
            }
            pq.pop();
        }

        return ans;
    }
};