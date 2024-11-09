class Solution {
public:
    // each number in the sequence must have all the set bits in x
    // this means each number must be at least x
    //
    // for the rest of the numbers in the sequence of length n,
    // to get all the numbers to AND to x, we should use the zero-ed bits in x
    // (because to get 1, all bits in the AND sequence need to be 1, 0 otherwise.)
    // e.g. x = 000100000b, we can use the 0 bits to construct our sequence
    // 
    // note that we dont need the actual sequence (although we can generate it)
    // the sequence of numbers (using the zero bits) will be (0b - (n-1)b)
    // since we only want the largest number i.e. (n-1)th index
    // just generate this number will do
    long long minEnd(int n, int x) {
        --n; // include x itself
        long long ans = x;
        for (int i = 0; i < 64 && n > 0; ++i) {
            if ((ans & (1ll << i)) == 0) {
                // cout << i << "\n";
                if (n % 2 == 1) {
                    ans |= (1ll << i);
                }
                n /= 2;
            }
        }
        return ans;
    }
};
// 6715154
// 7193485