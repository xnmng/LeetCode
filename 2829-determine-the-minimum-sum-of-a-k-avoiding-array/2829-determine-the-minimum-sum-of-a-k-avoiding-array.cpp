class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> s;
        int ans = 0;
        int cur = 1;
        while (s.size() != n) {
            if (s.find(k - cur) == s.end()) {
                ans += cur;
                s.insert(cur);
            }
            ++cur;
        }
        return ans;
    }
};