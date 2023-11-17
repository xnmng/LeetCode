class Solution {
public:
    int minMoves(vector<int>& nums) {
        long sum = 0;
        int minimum = INT_MAX;
        for (auto i : nums) {
            sum += i;
            minimum = min(minimum, i);
        }
        return sum - minimum * nums.size();
    }
};