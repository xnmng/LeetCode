class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long sum = 0;
        for (int i : nums) {
            sum += i;
            ++mp[i];
        }
        int n = nums.size();
        int ans = INT_MIN;
        int doublesum;
        int outlier;
        for (int i = n-1; i >= 0; --i) {
            outlier = nums[i];
            doublesum = sum - outlier;
            if (abs(doublesum) % 2 == 1) continue;
            --mp[outlier];
            if (mp[doublesum / 2] > 0) {
                ans = max(ans, nums[i]);    
            }
            ++mp[outlier];
        }
        return ans;
    }
};
// [6,-31,50,-35,41,37,-42,13]
// [752,678,-483,-583,201,0,-886,-474,-171]