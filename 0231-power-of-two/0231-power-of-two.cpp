class Solution {
public:
    // any number < 0 is not a power of 2
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};