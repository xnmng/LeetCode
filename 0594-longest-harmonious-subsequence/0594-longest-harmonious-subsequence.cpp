class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int i : nums) ++mp[i];
        int ans = 0;
        for (auto [k,v] : mp) {
            if (mp.find(k + 1) == mp.end()) continue;
            // cout << k << " " << v << " " << mp[k + 1] << " " << (int)(v + mp[k+1]);
            ans = max(ans, v + mp[k + 1]);
        }
        return ans;
    }
};