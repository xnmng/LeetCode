class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        auto n{cardPoints.size()};
        auto sum{0};
        for (auto i = 0; i < k; ++i) {
            sum += cardPoints[i];
        }
        auto ans{sum};
        auto left{k - 1};
        auto right{static_cast<int>(n-1)};
        while (left >= 0) {
            sum -= cardPoints[left];
            sum += cardPoints[right];
            ans = max(ans, sum);
            --left;
            --right;
            // cout << sum << " " << ans << "\n";
        }
        return ans;
    }
};

// [100,40,17,9,73,75]
// 3