class Solution {
public:
    // use kadanes to solve
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> v(26, INT_MAX);
        int n = chars.size();
        for (int i = 0; i < n; ++i) {
            v[chars[i] - 'a'] = vals[i];
        }
        for (int i = 0; i < 26; ++i) {
            if (v[i] == INT_MAX) v[i] = i+1;
        }

        int ans = 0;
        int sum = 0;
        for (char c : s) {
            sum += v[c - 'a'];
            ans = max(ans, sum);
            sum = max(0, sum);
        }
        return ans;
    }
};