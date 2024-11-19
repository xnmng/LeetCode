class Solution {
public:
    // note: cannot just reset when you find a duplicate! (e.g. [3,2,3,1])
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long sum = 0;
        int duplicateCount = 0;
        long long ans = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        while (right < n) {
            sum += nums[right];
            ++mp[nums[right]];
            if (mp[nums[right]] > 1) ++duplicateCount;
            if (right - left + 1 == k) {
                if (duplicateCount == 0) ans = max(ans, sum);
                if (mp[nums[left]] > 1) --duplicateCount;
                --mp[nums[left]];
                sum -= nums[left];
                ++left;
            }
            ++right;
        }
        return ans;
    }
};
// [3,2,3,1]