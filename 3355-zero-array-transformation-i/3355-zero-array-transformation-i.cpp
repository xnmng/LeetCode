class Solution {
public:
    // line sweep and check if there are any indexes that cant be made negative/zero
    //
    // note that you dont have to decrease all indexes in the [l, r] range
    // thus it suffices to check that all indexes can be made negative/zero
    // also note that all l, r are within n, so no need to check for validity
    // O(n + q) time, O(n) space
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> v(n+1, 0);
        for (auto& q : queries) {
            --v[q[0]];
            ++v[q[1] + 1];
        }
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += v[i];
            if (nums[i] + cur > 0) return false;
        }
        return true;
    }
};