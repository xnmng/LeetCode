class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int right = nums.size()-1;
        while (right >= 0 
               && nums[right] % 2 == 1) {
                --right;
        }
        for (auto i = 0; i < right; ++i) {
            if (nums[i] % 2 == 0) continue;
            else {
                swap(nums[right], nums[i]);
                while (right >= 0 
                       && nums[right] % 2 == 1) {
                    --right;
                }
            }
        }
        return nums;
    }
};

// [1]
// [1,3,0,5,2]
// [1,0,3]