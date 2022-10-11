// https://leetcode.com/problems/increasing-triplet-subsequence/discuss/78993/Clean-and-short-with-comments-C++

// maxn are the BEST candidates for the subsequence of size n NOT the actual candidates!
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int max1{-1};
        int max2{-1};
        for (auto i = 0; i < nums.size(); ++i) {
            if (max1 == -1 || nums[i] <= nums[max1]) {
                max1 = i;
            }
            else if (max2 == -1 || nums[i] <= nums[max2]) {
                max2 = i;
            }
            else if (nums[max2] < nums[i]) return true;
        }
        return false;
    }
};

// [3,4,1,5]
// [3,10,4,5]
// [1,1,-2,6]
