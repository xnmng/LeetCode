class Solution {
public:
    // work backwards, starting from target
    // - add 1 to target
    // - divide target by 2 (even only)
    //
    // once we reach a value of target <= startValue, 
    // add 1 till we reach same value as startValue
    //
    // why is it correct?
    // https://leetcode.com/problems/broken-calculator/discuss/234484/JavaC++Python-Change-Y-to-X-in-1-Line
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (target > startValue) {
            if (target % 2 == 0) {
                target /= 2;
            } else ++target;
            ++ans;
        }
        return startValue - target + ans;
    }
};