class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        for (int i : nums) {
            minimum = min(minimum, i);
            maximum = max(maximum, i);
        }
        return (long long)k * (maximum - minimum);
    }
};