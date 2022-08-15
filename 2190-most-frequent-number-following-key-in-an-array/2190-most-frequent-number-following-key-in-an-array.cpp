class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> mp;
        for (auto i = 0; i < nums.size()-1; ++i) {
            if (nums[i] == key) ++mp[nums[i+1]];
        }
        
        auto ans{-1};
        auto count{-1};
            
        for (auto [k,v] : mp) {
            if (v > count) {
                ans = k;
                count = v;
            }
        }
        
        return ans;
    }
};