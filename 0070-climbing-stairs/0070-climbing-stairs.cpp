class Solution {
public:
    
    int climbStairs(int n) {
        if (n < 3) return n;
        auto count{3};
        auto cur{3};
        auto prev{3};
        auto prevprev{2};
        while (count < n) {
            ++count;
            cur = prev + prevprev;
            prevprev = prev;
            prev = cur;
        }
        return cur;
    }
};