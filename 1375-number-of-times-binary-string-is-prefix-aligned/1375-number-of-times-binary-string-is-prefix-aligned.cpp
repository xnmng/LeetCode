// https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/discuss/532538/JavaC++Python-Straight-Forward-O(1)-Space

// for the string to be prefix aligned at flip x (1-based), 
// bits [1, x] should be ones, otherwise zero
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        auto cur{0};
        auto ans{0};
        for (auto i = 0; i < flips.size(); ++i) {
            cur = max(cur, flips[i]);
            if (cur == i+1) ++ans;
        }
        return ans;
    }
};