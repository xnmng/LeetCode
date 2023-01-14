class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if (tokens.size() == 0) return 0;
        auto cur{0};
        auto ans{0};
        sort(tokens.begin(), tokens.end());
        auto left{0};
        auto right{static_cast<int>(tokens.size() - 1)};
        if (power < tokens[0]) return ans;
        while (left <= right && left < tokens.size() && right >= 0) {
            while (left <= right && power >= tokens[left]) {
                power -= tokens[left];
                ++left;
                ++cur;
                ans = max(ans, cur);
            }
            if (right >= left) {
                power += tokens[right];
                --right;
                --cur;
            }
        }
        return ans;
    }
};

// [71,55,82]
// 54