class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        auto sum{0};
        auto n{chalk.size()};
        for (auto i = 0; i < n; ++i) {
            if (k < chalk[i]) return i;
            sum += chalk[i];
            k -= chalk[i];
        }
        k %= sum;
        for (auto i = 0; i < n; ++i) {
            if (k < chalk[i]) return i;
            k -= chalk[i];
        }
        return -1; // shouldnt happen
    }
};