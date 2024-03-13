class Solution {
public:
    // binary search (TODO)
    //
    // can also do math in constant time
    int pivotInteger(int n) {
        int total = (n) * (n+1) / 2;
        int sqrtTotal = sqrt(total);
        return sqrtTotal * sqrtTotal == total ? sqrtTotal : -1;
    }
};