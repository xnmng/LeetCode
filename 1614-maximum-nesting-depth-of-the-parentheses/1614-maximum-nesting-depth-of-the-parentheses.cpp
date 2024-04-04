class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int ans = 0;
        for (char c : s) {
            if (c == '(') ++count;
            if (c == ')') --count;
            ans = max(abs(count), ans);
        }
        return ans;
    }
};