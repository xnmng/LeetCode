class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        while (n > 0 || k > 0) {
            if (k % 2 == 1 && n % 2 == 0) return -1;
            else if (k % 2 != n % 2) ++ans;
            n /= 2;
            k /= 2;
        }
        return ans;
    }
};