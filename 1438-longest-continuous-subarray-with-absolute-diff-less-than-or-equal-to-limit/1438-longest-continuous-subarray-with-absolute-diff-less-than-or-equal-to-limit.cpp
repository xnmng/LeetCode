class Solution {
public:
    // TODO: read O(n) time, O(n) space solution
    //
    // subarray is contiguous
    // use multiset, O(nlogn) time, O(n) space
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int left = 0;
        int right = 0;
        int ans = 0;
        int n = nums.size();
        while (right < n) {
            s.insert(nums[right]);
            ++right;
            while (*s.rbegin() - *s.begin() > limit) {
                // DO NOT USE ERASE! erase removes ALL copies!
                auto itr = s.find(nums[left]);
                s.erase(itr);
                ++left;
            }
            ans = max(ans, (int) s.size());
        }
        return ans;
    }
};
// [2,2,2,4,4,2,5,5,5,5,5,2]
// 2