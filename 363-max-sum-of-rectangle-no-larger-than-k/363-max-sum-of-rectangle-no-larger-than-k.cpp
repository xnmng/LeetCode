class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        auto m{matrix.size()};
        auto n{matrix[0].size()};
        auto ans{INT_MIN};
        for (auto i = 0; i < n; ++i) {
            vector<int> prefixSum(m, 0); // prefix sum of each row
            for (auto j = i; j < n; ++j) {
                for (auto k = 0; k < m; ++k) {
                    prefixSum[k] += matrix[k][j];                
                }
                set<int> ordSet;
                ordSet.insert(0);
                auto sum{0};
                
                for (auto s : prefixSum) {
                    sum += s;
                    auto itr = ordSet.lower_bound(sum - k);
                    if (itr != ordSet.end()) {
                        ans = max(ans, sum - *itr);
                    }
                    ordSet.insert(sum);
                }
            }
        }
        return ans;
    }
};

// [[5,-4,-3,4],[-3,-4,4,5],[5,1,5,-4]]
// -2