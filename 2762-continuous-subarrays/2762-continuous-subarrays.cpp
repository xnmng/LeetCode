class Solution {
public:
    // note: subarrays have to be contiguous!
    // use map to sort the numbers encountered, O(nlogn) time, O(n) space
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        map<int,int> mp;
        while (right < n) {
            ++mp[nums[right]];
            while (mp.rbegin()->first - mp.begin()->first > 2) {
                --mp[nums[left]];
                if (mp[nums[left]] == 0) mp.erase(nums[left]);
                ++left;
            }
            ans += right - left + 1;
            ++right;
        }
        return ans;
    }
};