class Solution {
public:
    // get the degree of each node, sort by descending order, 
    // then give greedily values to each node and compute answer
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<long> v(n, 0); // use long to prevent overflow
        for (auto& road : roads) {
            ++v[road[0]];
            ++v[road[1]];
        }
        sort(v.rbegin(), v.rend());
        for (auto i : v) {
            ans += i * n;
            --n;
        }
        return ans;
    }
};