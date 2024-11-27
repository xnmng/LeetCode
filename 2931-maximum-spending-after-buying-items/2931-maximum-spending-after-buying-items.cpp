class Solution {
public:
    // at each step, just greedily take the smallest value possible to be bought
    // this is because on each day you earn (values[i][j] * d)
    // to maxmize the total of each product, leave larger values for larger values of d
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int m = values.size();
        int n = values[0].size();
        for (int i = 0; i < m; ++i) {
            pq.emplace(values[i].back(), i);
            values[i].pop_back();
        }
        long long ans = 0;
        long long d = 1;
        while (!pq.empty()) {
            auto [val, i] = pq.top();
            // cout << val << " " << i << " " << d << "\n";
            pq.pop();
            ans += val * d;
            ++d;
            if (!values[i].empty()) {
                pq.emplace(values[i].back(), i);
            values[i].pop_back();
            }
        }
        return ans;
    }
};