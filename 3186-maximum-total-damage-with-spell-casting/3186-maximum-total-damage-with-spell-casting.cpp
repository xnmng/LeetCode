class Solution {
public:
    // dp[i] stores the maximum total damage one can cast
    // dp[i] = max(skip casting this index, cast this index + prev)
    //
    // TODO: optimize this to O(1) space, since we dont care about smaller than power[i] - 3
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        unordered_map<int,long long> mp;
        vector<int> v;
        v.reserve(n);
        for (int i = 0; i < n; ++i) {
            ++mp[power[i]];
            if (mp[power[i]] == 1) v.emplace_back(power[i]);
        }
        sort(v.begin(), v.end());
        vector<long long> dp(v.size(), 0);
        dp[0] = mp[v[0]] * v[0];
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = mp[v[i]] * v[i];
            for (int j = i-1; j >= 0; --j) {
                if (v[i] - v[j] > 2) {
                    dp[i] += dp[j];
                    break;
                }
            }
            dp[i] = max(dp[i], dp[i-1]);
        }
        return dp.back();
    }
};
// [5,9,2,10,2,7,10,9,3,8]