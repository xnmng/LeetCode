class Solution {
public:
    // a little confused on why greedy defo works
    bool canMakeSubsequence(string str1, string str2) {
        int p1 = 0;
        int p2 = 0;
        int m = str1.size();
        int n = str2.size();

        while (p1 < m && p2 < n) {
            if (str1[p1] == str2[p2] ||
                str1[p1] + 1 == str2[p2] || 
                (str1[p1] - 25 == str2[p2])) { // 'z' -> 'a' case
                    ++p2;
            }
            ++p1;
        }
        return p2 == n;
    }
};