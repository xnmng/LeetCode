// https://leetcode.com/problems/put-marbles-in-bags/solution/
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> sums;
        sums.reserve(weights.size()-1);
        for (auto i = 1; i < weights.size(); ++i) {
            sums.emplace_back(weights[i] + weights[i-1]);
        }
        sort(sums.begin(), sums.end());
        auto ans{0ll};
        for (auto i = 0; i < k-1; ++i) {
            ans += sums[sums.size() - 1 - i] - sums[i];
        }
        return ans;
    }
};