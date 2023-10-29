// https://leetcode.com/problems/poor-pigs/discuss/94273/Solution-with-detailed-explanation
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // number of tests we can perform
        int tests = (minutesToTest / minutesToDie) + 1;
        int ans = 0;
        while (pow(tests, ans) < buckets) ++ans;
        return ans;
    }
};
// 125
// 1
// 4