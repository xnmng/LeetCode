class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        while (ans - 1 < n) {
            ans *= 2;
        }
        return ans - 1;
    }
};