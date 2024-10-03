class Solution {
public:
    // reduce the problem down to subarray sum equals k
    // use prefix sum
    // https://youtu.be/tZXsLAyE0SE?si=3nLTb1R4tE0N3Cgc
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        int n = nums.size();
        for (int i : nums) sum = (sum + i) % p;
        if (sum == 0) return 0;
        int goal = sum % p;
        int ans = INT_MAX;
        sum = 0;
        int needed;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            sum %= p;
            needed = (sum - goal + p) % p;
            
            if (mp.find(needed) != mp.end()) {
                ans = min(ans, i - mp[needed]);
            }
                
            mp[sum] = i;
        }
        
        if (ans == n) return -1;
        return ans;
    }
};
// [1,2,3]
// 7