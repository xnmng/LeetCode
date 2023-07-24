// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/discuss/1052527/JavaC++Python-O(1)-Space
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        auto maxi{0};
        auto mini{0};
        auto sum{0};
        for (auto& i : nums) {
            sum += i;
            maxi = max(maxi, sum);
            mini = min(mini, sum);
        }
        return maxi - mini;
    }
    
    // int maxAbsoluteSum(vector<int>& nums) {
    //     auto ans{0};
    //     auto cur{0};
    //     for (auto& i : nums) {
    //         cur += i;
    //         if (cur < 0) cur = 0;
    //         else ans = max(ans, cur);
    //     }
    //     cur = 0;
    //     for (auto& i : nums) {
    //         cur += i;
    //         if (cur > 0) cur = 0;
    //         else ans = max(ans, -1 * cur);
    //     }
    //     return ans;
    // }
};
// [-3,-5,-3,-2,-6,3,10,-10,-8,-3,0,10,3,-5,8,7,-9,-9,5,-8]