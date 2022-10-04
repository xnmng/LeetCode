class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> v;
        queue<int> q;
        q.push(0);
        int cur;
        while (v.size() != rooms.size() && !q.empty()) {
            cur = q.front();
            q.pop();
            if (v.find(cur) != v.end()) continue;
            v.insert(cur);
            for (auto i : rooms[cur]) {
                q.push(i);
            }
        }
        return v.size() == rooms.size();
    }
};