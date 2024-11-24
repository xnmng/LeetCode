class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;
        long long clockwise;
        long long anticlockwise;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int src = s[i] - 'a';
            int dest = t[i] - 'a';
            clockwise = 0;
            while (src != dest) {
                clockwise += nextCost[src];
                src = (src + 1) % 26;
            }
            src = s[i] - 'a';
            anticlockwise = 0;
            while (src != dest) {
                anticlockwise += previousCost[src];
                src = (src - 1 + 26) % 26;
            }
            ans += min(clockwise, anticlockwise);
        }
        return ans;
    }
};