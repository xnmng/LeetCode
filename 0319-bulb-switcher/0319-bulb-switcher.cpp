class Solution {
public:
    int bulbSwitch(int n) {
        auto ans{0};
        for (auto i = 1; i*i <= n; ++i) {
            ++ans;
        }
        return ans;
    }
};
/**
1 2 3 4 5 6
-----------
1 1 1 1 1 1
1 0 1 0 1 0
1 0 0 0 1 1
1 0 0 1 1 1
1 0 0 1 0 1
1 0 0 1 0 0
    
given a bulb how do we know if its on/off?
    
1 : 1           (on)
2 : 1 2         (off)
3 : 1 3         (off)
4 : 1 2 4       (on)
5 : 1 5         (off)
6 : 1 2 3 6     (off)
    
    even number of factors -> off 
    odd number of factors -> on 
    
    factors come in pairs, unless its a square number
**/