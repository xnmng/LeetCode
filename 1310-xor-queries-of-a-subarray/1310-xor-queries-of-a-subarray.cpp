class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix;
        prefix.reserve(n);
        int cur = 0;
        for (int i : arr) {
            cur ^= i;
            prefix.emplace_back(cur);
        }
        // for (auto i : prefix) cout << i << " ";
        // cout << "\n";
        vector<int> ans; 
        ans.reserve(queries.size());
        for (auto& i : queries) {
            if (i[0] == 0) {
                ans.emplace_back(prefix[i[1]]);
            } else {
                ans.emplace_back(prefix[i[1]] ^ prefix[i[0] - 1]);                
            }
        }
        return ans;
    }
};