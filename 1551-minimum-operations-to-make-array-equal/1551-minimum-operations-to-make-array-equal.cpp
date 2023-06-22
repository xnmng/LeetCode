// https://leetcode.com/problems/minimum-operations-to-make-array-equal/discuss/1145082/Simple-O(1)-1-Liner-or-Easy-Solution-w-Explanation-or-Beats-100
class Solution {
public:
    int minOperations(int n) {
        // [1, 3, 5, ..., 2n - 1]
        // (n / 2) * (2n - 1 + 1) (AP formula)
        // n^2
        auto sum{n * n}; // sum is n^2
        auto goal{sum / n}; // goal is n
        if (n % 2 == 1) {
            auto half{n/2};
            return half * (half + 1);
        }
        else return n * n / 4; // analogy: big triangle can be split into 4 smaller ones
    }
};
