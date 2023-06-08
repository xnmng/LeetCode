class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto left{0};
        while (left < nums.size()) {
            if (nums[left] != 0) ++left;
            else break;
        }
        // cout << left << "\n";
        if (left == nums.size()) return;
        auto right{left + 1};
        while (right < nums.size()) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                ++left;
            }
            ++right;
        }
        while (left < nums.size()) {
            nums[left] = 0;
            ++left;
        }
    }
};

// [2,1]