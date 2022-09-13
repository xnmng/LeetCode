class Solution {
public:
    int countElements(vector<int>& nums) {
        auto s{nums[0]};
        auto sc{1};
        auto b{nums[0]};
        auto bc{1};
        for (auto i = 1; i < nums.size(); ++i) {
            if (s == nums[i]) {
                ++sc;
            }
            if (b == nums[i]) {
                ++bc;
            }
            if (s > nums[i]) {
                s = nums[i];
                sc = 1;
            }
            if (b < nums[i]) {
                b = nums[i];
                bc = 1;
            }
        }
        return max(0, (int)nums.size() - sc - bc);
    }
};

// [0]