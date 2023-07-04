class Solution {
private:
    bool isOverlapping(int left1, int right1, int left2, int right2) {
        return max(right1, right2) - min(left1, left2) <= (right1 - left1 + right2 - left2);
    }
public:
    int countWays(vector<vector<int>>& ranges) {
        auto ans{2l};
        sort(ranges.begin(), ranges.end());
        auto left{ranges[0][0]};
        auto right{ranges[0][1]};
        auto modulo{static_cast<int>(1e9+7)};

        for (auto i = 1; i < ranges.size(); ++i) {
            if (isOverlapping(left, right, ranges[i][0], ranges[i][1])) {
                // cout << i << " is overlapping\n";
                // cout << left << " " << right << " " << ranges[i][0] << " " << ranges[i][1] << "\n";
                left = min(left, ranges[i][0]);
                right = max(right, ranges[i][1]);
            } else {
                // cout << left << " " << right << "\n";
                left = ranges[i][0];
                right = ranges[i][1];
                ans = (ans * 2) % modulo;
            }
        }
        return ans;
    }
};
// [[5,11],[20,22],[1,3],[21,22],[11,11]]