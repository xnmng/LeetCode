class Solution {
public:
    int minStartValue(vector<int>& nums) {
        auto minimum{INT_MAX};
        auto cur{0};
        for (auto i : nums) {
            cur += i;
            minimum = min(cur, minimum);
        }
        return minimum < 0 ? -1 * minimum + 1 : 1;
    }
};