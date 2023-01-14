// https://leetcode.com/problems/domino-and-tromino-tiling/solutions/116664/schematic-explanation-of-two-equivalent-dp-recurrence-formula/?orderBy=most_votes
class Solution {
public:
    int numTilings(int n) {
        long mod{static_cast<int>(1e9 + 7)};
        long p3 = -1;
        long p2 = 0;
        long p1 = 1;
        long cur;
        for (auto i = 1; i <= n; ++i) {
            cur = (p1 * 2 + p3) % mod;
            p3 = p2;
            p2 = p1;
            p1 = cur;
            // cout << i << " " << p1 << "\n";
        }
        return p1;
    }
};