class Solution {
public:
    // TODO: reimplement; had issues implementing
    // just put 0 in front, 2 behind lmao
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int cur = left;
        while (cur <= right) {
            if (nums[cur] == 0) {
                swap(nums[cur], nums[left]);
                ++left;
                ++cur;
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[right]);
                --right;
            } else ++cur;
            // for (auto i : nums) cout << i << " ";
            // cout << "\n";
        }
    }
};
