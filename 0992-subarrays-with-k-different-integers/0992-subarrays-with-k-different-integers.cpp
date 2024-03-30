class Solution {
public:
    // todo: (simple) 2 pass solution (at most k distinct integers approach)
    
    // use k to directly keep track of number of distinct elements
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        // sliding window will cause mp to have at most k+1 elements in the map
        mp.reserve(k+1);
        int n = nums.size();
        int left = 0;
        int right = 0;
        // kind of like a 'streak' counter, so we dont need recompute for [left, right]
        int count = 0; 
        int ans = 0;
        while (right < n) {
            ++mp[nums[right]];
            if (mp[nums[right]] == 1) --k;
            
            while (k < 0) {
                --mp[nums[left]];
                if (mp[nums[left]] == 0) {
                    ++k;
                    count = 0;
                }
                ++left;
            }
            
            if (k == 0) {
                while (mp[nums[left]] > 1) {
                    ++count;
                    --mp[nums[left]];
                    ++left;
                }
                ans += count + 1;
            }
            
            ++right;
        }
        return ans;
    }
};