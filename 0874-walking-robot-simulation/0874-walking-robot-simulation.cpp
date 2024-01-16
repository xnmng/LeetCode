class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>> dirs{{0,1}, {1,0}, {0,-1}, {-1,0}};
        int curDir = 0;
        int curX = 0;
        int curY = 0;
        int ans = 0;
        unordered_set<string> s; // store "<x-coord> <y-coord>" 
        for (auto i : obstacles) {
            s.insert(to_string(i[0]) + " " + to_string(i[1]));
        }
        for (auto i : commands) {
            switch (i) {
                case -2:
                    // math trick: turning left is the same as turning right 3 times
                    curDir = (curDir + 3) % 4;
                    break;
                case -1:
                    curDir = (curDir + 1) % 4;
                    break;
                default:
                    auto [x, y] = dirs[curDir];
                    for (auto j = 0; j < i; ++j) {
                        string next = to_string(curX + x) + " " + to_string(curY + y);
                        if (s.find(next) != s.end()) break;
                        curX += x;
                        curY += y;
                    }
                    ans = max(ans, curX * curX + curY * curY);
                    break;
            }
        }
        return ans;
    }
};