class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto i : nums) {
            ++mp[i];
        }
        vector<int> ans;
        for (auto [k,v] : mp) {
            if (mp.find(k+1) == mp.end()
               && mp.find(k-1) == mp.end()
               && v == 1) {
                ans.push_back(k);
            }
        }
        return ans;
    }
};