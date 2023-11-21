class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int start = -1;
        int cur = ' ';
        vector<vector<int>> ans;
        int n = s.size();
        for (auto i = 0; i < n; ++i) {
            if (s[i] != cur) {
                if (i - start >= 3) {
                    // prev index was the last letter matching cur
                    ans.push_back({start, i-1});
                }
                start = i;
                cur = s[i];
            }
        }
        if (n - start >= 3) {
            ans.push_back({start, n-1});
        }
        return ans;
    }
};