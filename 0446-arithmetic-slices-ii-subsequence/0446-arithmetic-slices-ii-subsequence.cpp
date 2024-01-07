// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/discuss/1455658/C++JavaPython-DP-with-Picture-explained-Clean-and-Concise
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int n = v.size();
        long long diff;
        // let dp[i][diff] represent the number of subsequences > len 2
        // ending at v[i] with difference diff
        vector<unordered_map<long long,int>> dp(n);
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // prevent overflow, cast first number to long long
                diff = (long long)v[i] - v[j];
                dp[i][diff] += dp[j][diff] + 1;
                ans += dp[j][diff];
            }
        }
        return ans;
    }
};
// [0,2000000000,-294967296]