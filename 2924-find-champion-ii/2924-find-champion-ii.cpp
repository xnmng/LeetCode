class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> v(n, 0);
        for (auto& i : edges) {
            ++v[i[1]];
        }
        int ans = -1;
        for (auto i = 0; i < n; ++i) {
            if (v[i] == 0 && ans != -1) return -1;
            if (v[i] == 0) ans = i;
        }
        return ans;
    }
};