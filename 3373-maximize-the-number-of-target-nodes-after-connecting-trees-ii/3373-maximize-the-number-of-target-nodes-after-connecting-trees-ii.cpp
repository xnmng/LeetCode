class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
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

        auto [c1, r1, b1] = helper(tree1, n);
        auto [_, r2, b2] = helper(tree2, m);
        int max2 = max(r2, b2);

        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            ans[i] = (c1[i] == 0 ? r1 : b1) + max2;
        }
        return ans;
    }

    tuple<vector<int>, int, int> helper(vector<vector<int>>& tree, int size) {
        vector<int> colour(size, -1);
        int red = 0;
        int blue = 0;
        queue<int> q;
        q.push(0);
        colour[0] = 0; // set node 0 to red as a convention
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            colour[node] == 0 ? ++red : ++blue;
            for (int i : tree[node]) {
                if (colour[i] < 0) {
                    colour[i] = 1 - colour[node];
                    q.push(i);
                }
            }
        }
        return make_tuple(colour, red, blue);
    }
};