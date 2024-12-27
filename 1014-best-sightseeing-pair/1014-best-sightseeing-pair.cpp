class Solution {
public:
    // values[i] + values[j] + i - j
    // (values[i] + i) + (values[j] - j)
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int iscore = values[0];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ans = max(ans, iscore + values[i] - i);
            iscore = max(iscore, values[i] + i);
        }
        return ans;
    }
};