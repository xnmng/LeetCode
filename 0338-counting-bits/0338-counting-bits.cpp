class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int offset{1};
        for (auto i = 1; i < n+1; ++i) {
            if (offset * 2 == i) offset *= 2;
            ans[i] = 1 + ans[i - offset];
        }
        return ans;
    }
};