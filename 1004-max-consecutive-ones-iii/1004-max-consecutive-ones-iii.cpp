class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        auto left{0};
        auto right{0};
        auto cur{0};
        auto ans{0};
        while (right < nums.size()) {
            ++cur;
            if (nums[right] == 0) --k;
            while (k < 0) {
                --cur;
                if (nums[left] == 0) ++k;
                ++left;
            }
            ans = max(ans, cur);
            ++right;
        }
        return ans;
    }
};

// [0,0,1,1,1,0,0]
// 0