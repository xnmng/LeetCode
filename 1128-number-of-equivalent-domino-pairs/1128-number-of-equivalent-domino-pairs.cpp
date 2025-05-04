class Solution {
public:
    // since small number of combinations, use bounded size container
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> count(100, 0);
        int ans = 0;
        int val;
        for (auto& i : dominoes) {
            val = min(i[0], i[1]) + 10 * max(i[0], i[1]);
            ans += count[val];
            ++count[val];
        }
        return ans;
    }
};