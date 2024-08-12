class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0;
        int y = 0;
        for (auto i : commands) {
            if (i == "UP") --x;
            if (i == "DOWN") ++x;
            if (i == "LEFT") --y;
            if (i == "RIGHT") ++y;
        }
        return (x * n) + y;
    }
};