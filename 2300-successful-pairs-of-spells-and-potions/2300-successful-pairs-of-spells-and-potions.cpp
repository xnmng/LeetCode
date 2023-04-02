// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/discuss/2138875/JavaC++Python-Straignt-Forward-with-Explantion
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (auto i : spells) {
            long need = (success + i - 1) / i;
            auto it = lower_bound(potions.begin(), potions.end(), need);
            ans.push_back(potions.end() - it);
        }
        return ans;
    }
};