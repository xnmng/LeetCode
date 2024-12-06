class Solution {
public:
    // greedy
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s(banned.begin(), banned.end());
        int next = 1;
        int ans = 0;
        while (next <= n && next <= maxSum) {
            if (!s.contains(next)) {
                ++ans;
                maxSum -= next;
            }
            ++next;
        }
        return ans;
    }
};