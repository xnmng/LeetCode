class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;

        auto maximum{nums[0]};
        auto cur{0};
        while (cur < nums.size() && cur <= maximum) {
            // cout << cur << " " << maximum << "\n";
            maximum = max(maximum, cur + nums[cur]);
            if (maximum >= nums.size()-1) return true;
            ++cur;
        }
        return false;
    }
};

// [1,2,3]