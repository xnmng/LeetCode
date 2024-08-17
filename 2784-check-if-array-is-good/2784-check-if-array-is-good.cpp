class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<bool> v(n, false);
        bool flag = false;
        for (auto i : nums) {
            if (i >= n || 
                (v[i] && i != n-1) || 
                (v[i] && i == n-1 && flag)) {
                // cout << i << "\n";
                return false;
            }
            if (v[i] && i == n-1) flag = true;
            v[i] = true;
        }
        return flag;
    }
};