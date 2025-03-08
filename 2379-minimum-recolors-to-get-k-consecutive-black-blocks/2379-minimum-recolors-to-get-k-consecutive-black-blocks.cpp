class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = k;
        int count = 0;
        int right = 0;
        int n = blocks.size();
        while (right < blocks.size()) {
            if (blocks[right] == 'W') ++count;
            if (right - k >= 0 && blocks[right - k] == 'W') --count;
            if (right + 1 >= k) {
                ans = min(ans, count);
            }
            ++right;
        }
        return ans;
    }
};