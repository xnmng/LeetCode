class Solution {
public:
    // best answer is when all '_' are either all 'L' or all 'R'
    // since it is symmetrical, just figure out number of '_', 
    //     and the abs. max value after applying all non-'_'(s)
    // 
    // O(n) time, O(1) space
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