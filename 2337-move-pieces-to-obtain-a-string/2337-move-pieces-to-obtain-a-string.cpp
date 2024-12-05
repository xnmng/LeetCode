class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int p1 = 0;
        int p2 = 0;
        while (p1 < n || p2 < n) {
            if (start[p1] == '_') ++p1;
            else if (target[p2] == '_') ++p2;
            else {
                if (start[p1] != target[p2]) return false;
                // at this point we know chars are the same
                else if (start[p1] == 'L') {
                    if (p1 < p2) return false;
                    ++p1;
                    ++p2;
                }
                else if (start[p1] == 'R') {
                    if (p1 > p2) return false;
                    ++p1;
                    ++p2;
                }
            }
        }
        return true;
    }
};