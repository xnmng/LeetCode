class Solution {
public:
    // sliding window
    // the window always moves to the right
    // https://leetcode.com/problems/defuse-the-bomb/solutions/948726/c-sliding-window-linear-time-and-constant-space-complexity
    vector<int> decrypt(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, 0);
        if (k == 0) return ans;
        int sum = 0;
        int left = 1;
        int right = k;
        if (k < 0) {
            k = -k;
            left = n-k;
            right = n-1;
        }
        for (int i = left; i <= right; ++i) {
            sum += nums[i];
        }
        // cout << left << " " << right << " " << n << "\n";
        for (int i = 0; i < n; ++i) {
            ans[i] = sum;
            sum -= nums[left];
            left = (left + 1) % n;
            right = (right + 1) % n;
            sum += nums[right];
        }
        return ans;
    }
};