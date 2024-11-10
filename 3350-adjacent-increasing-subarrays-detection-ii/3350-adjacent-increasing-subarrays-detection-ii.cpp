class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                v[i] = v[i - 1] + 1;
                ans = max(ans, v[i] / 2);
            }
        }
        for (int i = 1; i < n; ++i) {
            if (i - v[i] >= 0 && v[i - v[i]] >= v[i]) {
                ans = max(ans, v[i]);
            }
        }
        return ans;
    }
};

// [2,5,7,8,9,2,3,4,3,1]
// [1,2,3,4,4,4,4,5,6,7]
// [-16,-4,14,-9,13]
// [5,8,-2,-1]
// [-15,19]
