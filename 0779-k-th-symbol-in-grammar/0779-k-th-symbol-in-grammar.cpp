class Solution {
public:
    int kthGrammar(int n, int k) {
        int flips = 0;
        while (n != 1) {
            if (k <= pow(2, n-2)) {
                --n;
            } else {
                ++flips;
                k -= pow(2, n-2);
            }
        }
        return flips % 2 == 1 ? 1 : 0;
    }
};

// (1)  0
// (2)  01
// (4)  0110
// (8)  01101001
// (16) 0110100110010110
    
// each (n,k) is either (n-1, k) if k < 2^(n-1-1) or 