class Solution {
public:
    // O(1) time, O(1) space solution
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            if (((left >> i)  % 2) != ((right >> i) % 2)) break;
            if ((left >> i) % 2 == 1) ans += (1 << i);
        }
        return ans;
    }
};