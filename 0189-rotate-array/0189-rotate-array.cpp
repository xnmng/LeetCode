class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> res(nums.size() - k + 1, 0);
        for (int i = 0; i < nums.size() - k + 1; i++) {
            for (int j = 0; j < k; j++) {
                res[i] += nums[i+j];
            }
        }
        int max1 = res[0];
        int index1 = 0;
        int max2 = res[k] + max1;
        int index2 = k;
        int max3 = res[2 * k] + max2;
        int index3 = 2 * k;
        vector<int> ans = {index1, index2, index3};
        for (int i = 3 * k - 1; i < nums.size(); i++) {
            if (res[i - 3 * k + 1] > max1) {
                index1 = i - 3 * k + 1;
                max1 = res[index1];
            }
            if (res[i - 2 * k + 1] + max1 > max2) {
                index2 = i - 2 * k + 1;
                max2 = res[index2] + max1;
            }
            if (res[i - k + 1] + max2 > max3) {
                index3 = i - k + 1;
                max3 = res[index3] + max2;
                ans[0] = index1;
                ans[1] = index2;
                ans[2] = index3;
            }
        }
        return ans;
    }
};