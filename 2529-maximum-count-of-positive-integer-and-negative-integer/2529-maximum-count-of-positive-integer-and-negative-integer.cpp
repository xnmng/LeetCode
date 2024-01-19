class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount = 0;
        int posCount = 0;
        for (auto i : nums) {
            if (i < 0) ++negCount;
            else if (i > 0) ++posCount;
        }
        return max(negCount, posCount);
    }
};