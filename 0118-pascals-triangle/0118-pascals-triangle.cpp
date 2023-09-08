class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans{{1}};
        while (ans.size() != numRows) {
            vector<int> cur{1};
            size_t n{ans.back().size()};
            cur.reserve(n+1);
            for (int i = 0; i < n-1; ++i) {
                cur.emplace_back(ans.back()[i] + ans.back()[i+1]);
            }
            cur.emplace_back(1);
            ans.emplace_back(move(cur));
        }
        return ans;
    }
};