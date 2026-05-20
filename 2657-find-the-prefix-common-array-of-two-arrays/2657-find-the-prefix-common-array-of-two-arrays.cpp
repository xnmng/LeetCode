class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> ans(n);
        vector<bool> v1(n+1, false);
        vector<bool> v2(n+1, false);
        for (int i = 0; i < n; ++i) {
            v1[a[i]] = true;
            v2[b[i]] = true;
            for (int j = 0; j < n+1; ++j) {
                if (v1[j] && v2[j]) ++ans[i];
            }
        }
        return ans;
    }
};