class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int count = -1; // -1 for no 1 seen yet
        while (n > 0) {
            if (n % 2 == 1) {
                ans = max(ans, count);
                count = 1;
            }
            else {
                if (count >= 0) ++count;
            }
            n /= 2;
        }
        return ans;
    }
};