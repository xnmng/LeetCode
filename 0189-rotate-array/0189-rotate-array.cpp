class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + (n-k));
        reverse(nums.begin() + (n-k), nums.end());
        reverse(nums.begin(), nums.end());        
    }
};
// [-1]
// 2