class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int count = 0;
        for (int i : nums) {
           count += i < 10 ? i : -1 * i;
        }
        if (count == 0) return false;
        return true;
    }
};