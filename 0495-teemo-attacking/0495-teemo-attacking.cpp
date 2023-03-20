class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        auto ans{0};
        if (duration == 0) return ans;
        auto poison{timeSeries[0]};
        for (auto i = 1; i < timeSeries.size(); ++i) {
            if (timeSeries[i] - poison < duration) ans += timeSeries[i] - poison;
            else ans += duration;
            poison = timeSeries[i];
        }
        ans += duration;
        return ans;
    }
};

// [1,2,3,4,5,6,7,8,9]
// 0
// [1,3,5,7,9,11,13,15]
// 1