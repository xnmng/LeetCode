class Solution {
public:
    int minimumChairs(string s) {
        int count = 0;
        int ans = 0;
        for (char c : s) {
            if (c == 'E') ++count;
            else if (c == 'L') --count;
            ans = max(ans, count);
        }
        return ans;
    }
};