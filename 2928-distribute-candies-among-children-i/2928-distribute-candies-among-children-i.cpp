class Solution {
public:
    int distributeCandies(int n, int limit) {
        // test cases small enough to be brute-forced
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; i + j <= n; ++j) {
                for (int k = 0; i + j + k <= n; ++k) {
                    if (i <= limit 
                        && j <= limit 
                        && k <= limit 
                        && i + j + k == n) ++ans;
                }
            }
        }
        return ans;
    }
};