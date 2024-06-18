class Solution {
public:
    // TODO:
    // constraints small, can generate table of highest profit per difficulty
    //
    // greedy 2 pointers
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v; // <difficulty, profit>
        int n = difficulty.size();
        for (int i = 0; i < n; ++i) {
            v.emplace_back(difficulty[i], profit[i]);
        }
        sort(worker.begin(), worker.end());
        sort(v.begin(), v.end());
        int ans = 0;
        int maxProfit = 0;
        int index = 0; // index into v
        for (int i = 0; i < worker.size(); ++i) {
            while (index < n && worker[i] >= v[index].first) {
                maxProfit = max(maxProfit, v[index].second);
                ++index;
            }
            ans += maxProfit;
        }
        return ans;
    }
};