class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        if (k == 0) return vector<int>(n, 1);
        
        vector<vector<int>> tree1(n);
        vector<vector<int>> tree2(m);
        for (auto& i : edges1) {
            tree1[i[0]].emplace_back(i[1]);
            tree1[i[1]].emplace_back(i[0]);
        }
        for (auto& i : edges2) {
            tree2[i[0]].emplace_back(i[1]);
            tree2[i[1]].emplace_back(i[0]);
        }

        vector<int> r1 = helper(tree1, n, k);
        vector<int> r2 = helper(tree2, m, k-1);
        int r2max = *max_element(r2.begin(), r2.end());

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = r1[i] + r2max;
        }
        return ans;
    }

    vector<int> helper(vector<vector<int>>& adjlist, int size, int k) {
        vector<int> ans(size, 0);
        for (int i = 0; i < size; ++i) {
            queue<pair<int,int>> q;
            vector<bool> visited(size, false);
            q.push({i, 0});
            visited[i] = true;
            int count = 0;
            while (!q.empty()) {
                auto [node, dist] = q.front();
                q.pop();
                ++count;
                if (dist < k) {
                    for (int j : adjlist[node]) {
                        if (!visited[j]) {
                            visited[j] = true;
                            q.push({j, dist + 1});
                        }
                    }
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};