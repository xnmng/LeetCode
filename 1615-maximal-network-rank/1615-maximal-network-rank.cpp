class Solution {
public:
    // rank = indeg of i + indeg of j + (-1 if i and j are connected, else 0) 
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adjlist(n);
        for (auto& road : roads) {
            adjlist[road[0]].emplace_back(road[1]);
            adjlist[road[1]].emplace_back(road[0]);
        }
        auto ans{0};
        vector<bool> v;
        int count;
        for (auto i = 0; i < n; ++i) {
            for (auto j = i+1; j < n; ++j) {
                v = vector<bool>(n, false);
                count = adjlist[i].size() + adjlist[j].size();
                if (adjlist[i].size() < adjlist[j].size()) {
                    for (int& k : adjlist[i]) {
                        if (k == j) {
                            --count;
                            break;
                        }
                    }
                } else {
                    for (int& k : adjlist[j]) {
                        if (k == i) {
                            --count;
                            break;
                        }
                    }
                }
                // cout << i << " " << j << " " << count << "\n";
                ans = max(count, ans);
            }
        }
        return ans;
    }
};
// 2
// [[1,0]]