class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if (target > n*k || target < n) return 0;
        int modulo = 1e9 + 7;
        // initialize base case
        vector<long> v(target+1, 0);
        for (int i = 1; i <= k && i < target+1; ++i) {
            v[i] = 1;
        }
        int cur = 1;
        while (cur < n) {
            vector<long> next(target+1, 0);
            for (int i = 0; i < target+1; ++i) {
                for (int j = 1; i+j < target+1 && j <= k; ++j) {
                    next[i+j] = (next[i+j] + v[i]) % modulo;
                }
            }
            v = next;
            ++cur;
        }
        return v.back();
    }
};

// 2
// 5
// 10