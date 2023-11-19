class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if (s1[0] != s2[0] || s2[0] != s3[0]) return -1;
        int ans = 0;
        while (s1.size() != 1 
               || s2.size() != 1 
               || s3.size() != 1) {
            if (s1.size() > s2.size()) {
                s1.pop_back();
                ++ans;
            } else if (s2.size() > s3.size()) {
                s2.pop_back();
                ++ans;
            } else if (s3.size() > s1.size()) {
                s3.pop_back();
                ++ans;
            } else if (s1 != s2 || s2 != s3) {
                ans += 3;
                s1.pop_back();
                s2.pop_back();
                s3.pop_back();                
            } else break;
        }
        return ans;
    }
};
// "a"
// "aabc"
// "a"