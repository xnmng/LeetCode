class Solution {
public:
    // 2 pointers sliding window, find longest length possible
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            maxCost -= abs(s[right] - t[right]);
            ++right;
            while (maxCost < 0) {
                maxCost += abs(s[left] - t[left]);
                ++left;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};