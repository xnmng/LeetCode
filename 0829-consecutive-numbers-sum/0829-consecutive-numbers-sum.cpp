class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 1;
        // subtract off the diff, 
        // make sure that it is both a whole number and greater than 0
        //
        // aka attempt to find a "base number" such that base is > 0
        for (int i = 2; (i-1) * i / 2 < n; ++i) {
            if ((n - ((i-1) * i / 2)) % i == 0 && 
                (n - ((i-1) * i / 2)) / i != 0) ++ans;
        }
        return ans;
    }
};
// 1 2 3 4 5
// 0 1 2 3 4
// 4 * 5 / 2
// (n-1) * n / 2