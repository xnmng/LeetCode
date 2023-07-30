class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        auto sum{0ll};
        for (auto i = 0; i < nums1.size(); ++i) {
            sum += nums1[i];
            sum -= nums2[i];
        }
        if (sum != 0) return -1;
        auto ans{0ll};
        for (auto i = 0; i < nums1.size(); ++i) {
            if (k == 0) {
                if (nums1[i] != nums2[i]) return -1;
            } else {
                if (abs(nums1[i] - nums2[i]) % k != 0) return -1;
                ans += abs(nums1[i] - nums2[i]) / k;
            }
        }
        return ans/2;
    }
};
// [10,5,15,20]
// [20,10,15,5]
// 0