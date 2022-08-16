class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> v1;
        vector<int> v2;
        for (auto i = 1; i < sqrt(n); ++i) {
            if (n % i == 0) {
                v1.push_back(i);
                v2.push_back(n / i);
            }
        }
        auto sqn{static_cast<int>(sqrt(n))};
        if (sqn * sqn == n) v1.push_back(sqn);
        
        if (v1.size() + v2.size() < k) return -1;
        if (v1.size() > k-1) return v1[k-1];
        return v2[v2.size() - (k - 1 - v1.size()) - 1];
    }
};