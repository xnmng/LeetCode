class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if (target > n*k || target < n) return 0;
        if (n == 1) return n;
        
        vector<long> v(k+1, 1);
        v[0] = 0;
        
        auto cur{2};
        while (cur <= n) {
            vector<long> next(v.size()+k, 0);
            for (auto i = 0; i < v.size(); ++i) {
                for (auto j = 1; j <= k; ++j) {
                    if (i+j < next.size()) next[i+j] += v[i];
                    next[i+j] %= static_cast<long>(1e9 + 7);
                }
            }
            
            // for (auto i : v) cout << i << " ";
            // cout << "\n";
            
            v = next;
            ++cur;
        }
        return static_cast<int>(v[target]);
    }
};

// 2
// 5
// 10