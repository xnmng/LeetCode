class Solution {
public:
    // TODO: quickselect algorithm (same time complexity, better average runtime)
    // https://leetcode.com/problems/two-city-scheduling/discuss/278716/C++-O(n-log-n)-sort-by-savings
    
    // assume all are going to A, try to minimize by picking half to go to B
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> diff;
        diff.reserve(n);
        int ans = 0;
        for (auto& i : costs) {
            ans += i[0];
            diff.emplace_back(i[0] - i[1]);
        }
        sort(diff.rbegin(), diff.rend());
        for (auto i = 0; i < n/2; ++i) {
            ans -= diff[i];
        }
        return ans;
    }
};