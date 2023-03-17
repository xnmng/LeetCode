class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        auto mini{0ll};
        auto maxi{0ll};
        auto cur{0ll};
        for (auto i : differences) {
            cur += i;
            mini = min(mini, cur);
            maxi = max(maxi, cur);
        }
        return max(0ll, upper - lower + 1 - (maxi - mini));
    }
};