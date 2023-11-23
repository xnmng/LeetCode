/*
I kinda get it why it's asked by 'G', but asking this as a follow up...
There's Mo's algorithm to solve the problem. Snap.. and the problem is hard.

https://cp-algorithms.com/data_structures/sqrt_decomposition.html#mos-algorithm
https://www.scaler.com/topics/data-structures/mos-algorithm/
Errichto's explanation (https://www.youtube.com/watch?v=BJhzd_VG61k)
*/
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int n = l.size();
        ans.reserve(n);
        for (auto i = 0; i < n; ++i) {
            multiset<int> s(nums.begin() + l[i], nums.begin() + r[i] + 1);
            int prev = INT_MAX;
            int diff = INT_MAX;
            for (auto i : s) {
                if (prev == INT_MAX) prev = i;
                else if (diff == INT_MAX) {
                    diff = i - prev;
                    prev = i;
                } else {
                    if (i - prev != diff) {
                        ans.emplace_back(false);
                        diff = -1;
                        break;
                    }
                    prev = i;
                }
            }
            if (diff != -1) ans.emplace_back(true);
        }
        return ans;
    }
};
// [1,2,10,-6,-7,8,16,0,0,10,20,15,-2,-3,-1,-4,-4,-8,-2]
// [14,5,11,15,12,13,9,7,0]
// [15,8,14,18,15,16,12,8,1]