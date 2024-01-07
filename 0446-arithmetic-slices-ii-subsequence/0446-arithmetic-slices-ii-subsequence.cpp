// #define LL long long
// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& A) {
//         int n = A.size();
//         LL ans = 0;
//         vector<map<LL, int>> cnt(n);
//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 LL delta = (LL)A[i] - (LL)A[j];
//                 int sum = 0;
//                 if (cnt[j].find(delta) != cnt[j].end()) {
//                     sum = cnt[j][delta];
//                 }
//                 cnt[i][delta] += sum + 1;
//                 ans += sum;
//             }
//         }

//         return (int)ans;
//     }
// };

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
                diff = (long long)v[i] - v[j];
                dp[i][diff] += dp[j][diff] + 1;
                ans += dp[j][diff];
            }
        }
        return ans;
    }
};
// [0,2000000000,-294967296]