class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, pivot);
        int left = 0;
        int right = n-1;
        for (int i : nums) {
            if (i < pivot) {
                ans[left] = i;
                ++left;
            }
            else if (i > pivot) {
                ans[right] = i;
                --right;
            }
        }
        for (int i = 1; i+right < n; ++i) {
            // cout << i+right << " " << n-i << "\n";
            if (i+right > n-i) break;
            swap(ans[i+right], ans[n-i]);
        }
        return ans;
    }
};
// [19,15,12,-14,8,-7,-11]
// -7