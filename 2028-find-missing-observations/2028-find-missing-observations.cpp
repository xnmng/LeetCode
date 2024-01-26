class Solution {
public:
    // we know
    // - mean * (m+n)
    // - m rolls (aka sum of m)
    // determine if solution for n rolls
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for (auto i : rolls) {
            sum += i;
        }
        int missingSum = mean * (rolls.size() + n) - sum;

        // check edge case
        if (missingSum < n || missingSum > n*6) return {};

        vector<int> ans(n, 1);
        missingSum -= n;
        int index = 0;
        while (index < n && missingSum >= 0) {
            ans[index] += min(missingSum, 5);
            ++index;
            missingSum -= min(missingSum, 5);
        }
        return ans;
    }
};