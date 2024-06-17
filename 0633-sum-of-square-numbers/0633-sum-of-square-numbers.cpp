class Solution {
public:
    // TODO: read possible solutions 
    // https://leetcode.com/problems/sum-of-square-numbers/solution/
    //
    // brute force w caching (uset)
    bool judgeSquareSum(int c) {
        unordered_set<long> s;
        long cur;
        for (long i = 0; i * i <= c; ++i) {
            cur = i * i;
            s.insert(cur);
            if (s.find(c - cur) != s.end()) return true;
        }
        return false;
    }
};