class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incrCount = 0;
        int prevIncr = 0;
        int decrCount = 0;
        int prevDecr = INT_MAX;
        int ans = 1; // at least 1 element in nums
        for (auto i : nums) {
            if (i > prevIncr) {
                prevIncr = i;
                ++incrCount;
                ans = max(ans, incrCount);
            } else {
                incrCount = 1;
                prevIncr = i;
            }
            if (i < prevDecr) {
                prevDecr = i;
                ++decrCount;
                ans = max(ans, decrCount);
            } else {
                decrCount = 1;
                prevDecr = i;
            }            
        }
        return ans;
    }
};