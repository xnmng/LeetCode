class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count = 0;
        int left = 0;
        int right = 0;
        for (char c : moves) {
            if (c == 'L') ++left;
            else if (c == 'R') ++right;
            else if (c == '_') ++count;
        }
        return abs(left - right) + count;
    }
};