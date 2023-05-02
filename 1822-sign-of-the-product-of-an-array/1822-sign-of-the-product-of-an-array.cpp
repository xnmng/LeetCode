class Solution {
public:
    int arraySign(vector<int>& nums) {
        auto cur{1};
        for (auto i : nums) {
            if (i == 0) return 0;
            if (i < 0) cur *= -1;
        }
        return cur;
    }
};