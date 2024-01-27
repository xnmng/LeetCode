class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int ans = 0;
        int diff = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1]) {
                ++diff;
                if (diff == 1) ans = nums.size() - i;
                else if (diff > 1) break;
            }
        }
        
        switch (diff) {
            case 2:
                return -1;
            case 1:
                return nums.front() < nums.back() ? -1 : ans;
            default:
                return 0;
        }
    }
};