class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int left = 0;
        int right = 0;
        int n = nums.size();
        vector<int> v(32, 0);
        while (right < n) {
            if (nums[right] >= k) return 1; // edge case, can return early
            add(v, nums[right]);
            while (helper(v) >= k) {
                // cout << helper(v) << "\n";
                ans = min(ans, right - left + 1);
                // cout << ans << "\n";
                remove(v, nums[left]);
                ++left;
            }
            ++right;
        }
        return ans == INT_MAX ? -1 : ans;
    }
    
    int helper(vector<int>& v) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if (v[i] > 0) ans += (1 << i);
        }
        return ans;
    }
    
    void add(vector<int>& v, int i) {
        int index = 0;
        while (i > 0) {
            v[index] += (i % 2);
            i /= 2;
            ++index;
        }
    }
    
    void remove(vector<int>& v, int i) {
        int index = 0;
        while (i > 0) {
            v[index] -= (i % 2);
            i /= 2;
            ++index;
        }
    }
};