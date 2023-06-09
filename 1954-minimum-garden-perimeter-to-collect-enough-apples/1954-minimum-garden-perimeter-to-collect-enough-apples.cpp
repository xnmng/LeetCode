// https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/discuss/1375507/Brute-force-with-picture
// https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/discuss/1375396/O(1)-Cardano's-formula
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long n = 0;
        while (2 * n * (n + 1) * (1 + 2 * n) < neededApples)
            ++n;
        return  n * 8;
    }
};