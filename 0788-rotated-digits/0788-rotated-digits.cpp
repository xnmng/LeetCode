class Solution {
public:
    // invalid digits are 3 4 and 7
    // complement rule?
    //
    // number must not contain only 0, 1, 8
    // dp solution:
    // -1 is invalid
    // 1 is valid
    // 2 is invalid (but rotated digits)
    int rotatedDigits(int n) {
        vector<int> dp(n+1, -1);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 10 == 3 || i % 10 == 4 || i % 10 == 7) {
                dp[i] = -1;
            }
            else if (i % 10 == 0 || i % 10 == 1 || i % 10 == 8) {
                dp[i] = (i / 10 == 0) ? 2 : dp[i / 10];
            }
            else { // 2, 5, 6, 9
                dp[i] = (i / 10 == 0) ? 1 : dp[i / 10];
                if (dp[i] == 2) dp[i] = 1;
            }
            if (dp[i] == 1) ++ans;
            // cout << i << " " << dp[i] << "\n";
        }
        return ans;
    }
};
// 857