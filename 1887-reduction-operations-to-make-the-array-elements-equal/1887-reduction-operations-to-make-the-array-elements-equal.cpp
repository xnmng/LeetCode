class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> mp;
        for (auto i : nums) {
            ++mp[i];
        }
        int ans = 0;
        int count = 0;
        for (auto i = mp.rbegin(); next(i) != mp.rend(); ++i) {
            count += i->second;
            ans += count;
        }
        return ans;
    }
};