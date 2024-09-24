class Solution {
public:
    // brute force works, but we can do better!
    // use math to calculate
    //
    // to go from 0 -> n-1 -> 0 takes 2 * (n-1) steps
    // take modulo of k with (2 * (n-1))
    // if k is now smaller than n-1, return k (0 -> k, in k steps)
    // else, we will reach n-1, then come back
    // effectively, starting from n-1 and moving (k - (n-1)) steps back to origin
    // return n-1 - (k - (n-1))
    int numberOfChild(int n, int k) {
        k %= (2 * (n - 1));
        if (k <= n-1) return k;
        return n-1 - (k - (n-1));
    }
};