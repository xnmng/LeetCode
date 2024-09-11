class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        int cur = start ^ goal;
        while (cur != 0) {
            ans += cur % 2;
            cur /= 2;
        }
        return ans;
    }
};
// 10
// 82