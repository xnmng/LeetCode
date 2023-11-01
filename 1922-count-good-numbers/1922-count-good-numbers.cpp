// https://leetcode.com/problems/count-good-numbers/discuss/1314322/C++-(-5-even-indices)-*-(4-odd-indices)-with-explanation
class Solution {
    long long helper(int base, long long power, int modulo) {
        if (power == 0) return 1;
        long long res = helper(base, power / 2, modulo);
        if (power % 2 == 0) {
            return (res * res) % modulo;
        } else {
            return (((res * res) % modulo) * base) % modulo;
        }
    }
public:
    int countGoodNumbers(long long n) {
        // even indices: 0, 2, 4, 6, 8
        //  odd indices: 2, 3, 5, 7
        int modulo = 1e9+7;
        // 0-indexed
        long long oddIndices = n / 2;
        long long evenIndices = (n+1) / 2;
        return (helper(5, evenIndices, modulo) * helper(4, oddIndices, modulo)) % modulo;
    }
};