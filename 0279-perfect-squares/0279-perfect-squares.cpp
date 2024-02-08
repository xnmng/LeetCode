// https://leetcode.com/problems/perfect-squares/discuss/1520447/c++-dp-easy-to-understand
class Solution {
public:
    // dp, initialize base case to perfect square numbers
    // for a given integer i, check all possible j that are < i
    // i.e. dp[i] = min(dp[i], dp[j - i] + 1);
    int numSquares(int n) {
        vector<int> v(n+1, INT_MAX);
        for (auto i = 1; i*i < n+1; ++i) {
            v[i*i] = 1;
        }
        for (auto i = 2; i < n+1; ++i) {
            if (v[i] == 1) continue;
            for (auto j = 1; i - j*j >= 0; ++j) {
                v[i] = min(v[i], 1 + v[i - (j * j)]);
            }
        }
        return v[n];
    }
};