class Solution {
public:
    // swap first adjacent after leading zeros with same parity, and smaller
    string getSmallestString(string s) {
        int start = 0;
        int n = s.size();
        while (s[start] == '0' && start < n) ++start;
        for (int i = start + 1; i < n; ++i) {
            if ((s[i] - '0') % 2 == (s[i-1] - '0') % 2 &&
                s[i-1] > s[i]) { 
                swap(s[i], s[i-1]);
                break;
            }
        }
        return s;
    }
};